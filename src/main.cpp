#include <iostream>

#include "../include/CharacterSchema.h"
#include "../include/Mongodb.h"
#include "mongocxx/instance.hpp"

int main() {
  mongocxx::instance instance;
  server::API api;

  api.DeleteCharacter("62de1b22e9f58429e60d9cb2");
  return 0;
}
