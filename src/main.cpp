#include <iostream>

#include "../include/CharacterSize.h"
#include "../include/Mongodb.h"
#include "mongocxx/instance.hpp"

int main() {
  mongocxx::instance instance;
  server::API api;

  api.PostCharacter("Donkey Kong", server::CharacterSize::Large, 0);
  std::cout << "Hello World!";
  return 0;
}
