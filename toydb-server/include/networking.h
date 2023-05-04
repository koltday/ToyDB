
#ifndef __NETWORKING_H__
#define __NETWORKING_H__
#include <arpa/inet.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <unistd.h>
namespace ToyDB {

class Socket {
  char msg[1500];
  sockaddr_in address;
  int max_connections = 5;
  bool active = false;
  int port;
  int description;

public:
  Socket() {
    // memset(&msg, 0, sizeof(msg));
    bzero((char *)&address, sizeof(address));
  }

  int get_port() { return this->port; }

  void set_port(int port) { this->port = port; }

  sockaddr_in get_address() { return this->address; }

  void set_address(sockaddr_in socket_address) {
    this->address = socket_address;
  }

  void initialize_address(sa_family_t family, in_addr_t addr, in_port_t port) {
    this->address.sin_family = family;
    this->address.sin_addr.s_addr = addr;
    this->address.sin_port = port;
  }

  void initialize_descriptor() {
    this->description = socket(AF_INET, SOCK_STREAM, 0);
    if (this->description < 0) {
      std::cerr << "Error establishing the server socket." << std::endl;
    }
  }

  Socket(const char &ip_address, const int port) {
    struct hostent *host = gethostbyname(&ip_address);
  }

  bool connect() {
    int status = ::connect(this->description, (struct sockaddr *)&address,
                           sizeof(this->address));
    if (status < 0) {
      std::cout << "Error connecting to socket!" << std::endl;
    }

    return true;
  };
  int accept(sockaddr_in address, socklen_t client_address_size) {
    int status =
        ::accept(this->description, (sockaddr *)&address, &client_address_size);

    return status;
  };
  bool close();
  bool bind() {
    int bindStatus =
        ::bind(description, (struct sockaddr *)&address, sizeof(address));
    if (bindStatus < 0) {
      std::cerr << "Error binding socket to local address" << std::endl;
      exit(0);
    }
    return true;
  }

  void listen() { ::listen(this->description, max_connections); };
  std::string get_ip_address();
  int get_identifier();
  void hear(int identifier) {
    std::string message;
    clear_buffer();
    recv(identifier, (char *)&msg, sizeof(msg), 0);
  };

  void tell(int descriptor, std::string data) {
    clear_buffer();
    strcpy(msg, data.c_str());
    send(descriptor, (char *)&msg, strlen(msg), 0);
  };

  std::string tell_and_flush();
  void clear_buffer() { memset(&msg, 0, sizeof(msg)); }
  const char *get_message_buffer() { return msg; }
};

class ServerSocket : Socket {
private:
  sockaddr_in client_address;
  int client_descriptor;

public:
  ServerSocket(const int &port) { this->set_port(port); }

  bool start_server() {
    initialize_address(AF_INET, htonl(INADDR_ANY), this->get_port());
    initialize_descriptor();
    bind();
    std::cout << "Waiting for a client to connect..." << std::endl;

    socklen_t client_address_size = sizeof(client_address);

    int client_descriptor = this->accept(client_address, client_address_size);
    if (client_descriptor < 0) {
      std::cerr << "Error accepting request from client!" << std::endl;
      exit(1);
    }

    std::cout << "Connected with client!\n";

    while (1) {
      std::string message;
      std::cout << "Awaiting client response..." << std::endl;
      hear(client_descriptor);

      std::cout << "Client: " << get_message_buffer() << std::endl;
      std::cout << ">";
      std::getline(std::cin, message);
      tell(client_descriptor, message);
    }
    return true;
  };
};

class ClientSocket : Socket {
  struct hostent *host;

public:
  ClientSocket(char *ip_address, int port) {
    host = gethostbyname(ip_address);
    initialize_address(
        AF_INET, inet_addr(inet_ntoa(*(struct in_addr *)*host->h_addr_list)),
        port);
    initialize_descriptor();
    this->connect();
    while (1) {
      std::cout << ">";
      std::string data;
      getline(std::cin, data);
      tell(this->get_identifier(), data);
      std::cout << "Awaiting server response..." << std::endl;
      hear(this->get_identifier());
      std::cout << "Server: " << this->get_message_buffer() << std::endl;
    }
  }
};

} // namespace ToyDB
#endif
