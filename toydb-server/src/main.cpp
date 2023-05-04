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

#include "../include/networking.h"
#include "../include/serversocket.h"
#include "../include/socketexception.h"
#include "../include/toydb.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <vector>

int main() {
  ToyDB::ToyDB toydb;
  std::string username, password;
  std::cout << "Welcome to ToyDB.\n";
  // std::cout << "Enter username: ";
  // std::getline(std::cin, username);
  // std::cout << "Enter password: ";
  // std::getline(std::cin, password);

  // if (toydb.compare_login(username, password)) {
  // std::cout << "Success";
  // } else {
  // std::cout << "Failure";
  // }

  std::cout << "Testing server.\n";

  try {
    // ServerSocket server(1028);
    ToyDB::ServerSocket *server_socket = new ToyDB::ServerSocket(1028);
    server_socket->start_server();
    // while (true) {
    // ServerSocket new_sock;
    // server.accept(new_sock);
    // try {
    // new_sock << "You are connected. Please enter your username.";
    // new_sock >> username;
    // printf("%s", username.c_str());
    // new_sock << "Password.";
    // new_sock >> password;
    // printf("%s", password.c_str());
    // while (true) {
    // std::string data;
    // new_sock >> data;
    // printf("%s\n", data.c_str());
    // new_sock << data;
    // }
    // } catch (SocketException &) {
    // }
    // }
  } catch (SocketException &e) {
    std::cout << e.what();
  }
}
