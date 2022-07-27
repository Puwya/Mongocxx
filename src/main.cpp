#include <iostream>

#include "../include/CharacterSchema.h"
#include "../include/Mongodb.h"
#include "mongocxx/instance.hpp"

int main() {
  mongocxx::instance instance;
  server::API api;

  api.PatchWins("62e1abd35b528f48bf071941");
  return 0;
}
