#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "socketexception.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

class Socket {
public:
  Socket();
  virtual ~Socket();

  bool create();
  bool bind(const int port);
  bool listen() const;
  bool accept(Socket &) const;

  bool connect(const std::string host, const int port);

  bool send(const std::string) const;
  int recv(std::string &) const;

  void set_non_blocking(const bool);
  bool is_valid() const { return m_sock != -1; }

private:
  int m_sock;
  sockaddr_in m_addr;
  int max_host_name, max_connections, max_receive;
};

#endif
