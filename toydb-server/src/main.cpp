#include "../include/toydb.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  ToyDB::ToyDB toydb;
  std::string username, password;
  std::cout << "Welcome to ToyDB.\n";
  std::cout << "Enter username: ";
  std::getline(std::cin, username);
  std::cout << "Enter password: ";
  std::getline(std::cin, password);

  if (toydb.compare_login(username, password)) {
    std::cout << "Success";
  } else {
    std::cout << "Failure";
  }
}
