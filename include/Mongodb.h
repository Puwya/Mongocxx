#ifndef MONGODB_H_
#define MONGODB_H_
#include <cstdint>
#include <iostream>
#include <string>

#include "CharacterSchema.h"
#include "bsoncxx/builder/stream/document.hpp"
#include "bsoncxx/json.hpp"
#include "bsoncxx/oid.hpp"
#include "mongocxx/client.hpp"
#include "mongocxx/database.hpp"
#include "mongocxx/uri.hpp"

namespace server {
constexpr char MONGO_DB_URI[] = "mongodb://0.0.0.0:27017";
constexpr char DATABASE[] = "Mongocxx";
constexpr char COLLECTION_NAME[] = "MarioKartCharacter";

class API {
 public:
  API()
      : uri_(mongocxx::uri(MONGO_DB_URI)),
        client_(mongocxx::client(uri_)),
        db_(client_[DATABASE]) {}

  bool PostCharacter(
      const std::string &character_name, const CharacterSchema::Size &size,
      const int16_t &wins) {
    mongocxx::collection collection = db_[COLLECTION_NAME];
    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::document::value document =
        builder << "character" << character_name << "size"
                << CharacterSchema::SizeToString.find(size)->second << "wins" << wins
                << bsoncxx::builder::stream::finalize;
    try {
      collection.insert_one(document.view());
      return true;
    } catch (...) {
      std::cout << "Document was not inserted\n";
    }
    return false;
  }

  bool PatchWins(const std::string &character_id) {
    mongocxx::collection collection = db_[COLLECTION_NAME];
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::oid document_id(character_id);

    bsoncxx::document::value query_document =
        builder << "_id" << document_id << bsoncxx::builder::stream::finalize;

    bsoncxx::document::value document =
        builder << "$inc" << bsoncxx::builder::stream::open_document << "wins" << 1
                << bsoncxx::builder::stream::close_document
                << bsoncxx::builder::stream::finalize;

    bsoncxx::stdx::optional<mongocxx::result::update> result =
        collection.update_one(query_document.view(), document.view());

    if (result) {
      return result->modified_count() == 1;
    }
    return false;
  }
  bool DeleteCharacter(const std::string &character_id) { return true; }

 private:
  mongocxx::uri uri_;
  mongocxx::client client_;
  mongocxx::database db_;
};
};  // namespace server

#endif  // MONGODB_H_