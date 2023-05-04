/***************************************
ToyDB server: a basic database management system built for learning and
demonstration.
Copyright (C) 2023 Kolt Day

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
***************************************/

#include "../include/clientsocket.h"
#include "../include/socketexception.h"
#include "../include/toydb.h"
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <vector>
bool clear_authentication(ClientSocket clientsocket) {
  // std::string username;
  // std::string password;
  // std::string serverspeak;
  // clientsocket >> serverspeak;
  // printf("\n%s", serverspeak.c_str());
  // clientsocket >> serverspeak;
  // printf("\n%s", serverspeak.c_str());
  // std::getline(std::cin, username);
  // clientsocket << username;
  // clientsocket >> serverspeak;
  // printf("\n%s", serverspeak.c_str());
  // std::getline(std::cin, password);
  // clientsocket << password;
  // clientsocket >> serverspeak;
  // printf("\n%s", serverspeak.c_str());
  return true;
}
int main() {
  try {
    ClientSocket client_socket("localhost", 1028);
    std::string reply;
    std::string message;

  } catch (SocketException &e) {
    std::cout << "Exception was caught:" << e.what() << "\n";
  }

  return 0;
}
