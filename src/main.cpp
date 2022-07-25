#include <iostream>

#include "../include/CharacterSchema.h"
#include "../include/Mongodb.h"
#include "mongocxx/instance.hpp"

int main() {
  mongocxx::instance instance;
  server::API api;

  api.PatchWins("62de180f31de596774050941");
  return 0;
}
