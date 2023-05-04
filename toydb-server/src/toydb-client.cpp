#include "../include/networking.h"
#include <iostream>
#include <string>

int main() {
  ToyDB::ClientSocket *client = new ToyDB::ClientSocket("127.0.0.1", 1028);
}
