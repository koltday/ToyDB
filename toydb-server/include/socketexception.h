#ifndef __SOCKETEXCEPTION_H__
#define __SOCKETEXCEPTION_H__
#include <exception>
#include <string>

class SocketException : std::exception {
  std::string message;

public:
  // TODO: implement error codes instead
  SocketException(const std::string &message) { this->message = message; }
  const char *what() const noexcept override { return message.c_str(); }
};

#endif
