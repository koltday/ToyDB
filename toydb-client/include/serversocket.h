#ifndef __SERVERSOCKET_H__
#define __SERVERSOCKET_H__

#include "socket.h"

class ServerSocket : private Socket {
public:
  ServerSocket(int port);
  ServerSocket(){};
  virtual ~ServerSocket();

  const ServerSocket &operator<<(const std::string &) const;
  const ServerSocket &operator>>(std::string &) const;

  void accept(ServerSocket &);
};

#endif
