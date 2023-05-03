#include <string>

#ifndef __USER_H__
#define __USER_H__

namespace ToyDB {
class User {
private:
  std::string username;
  std::string password;

public:
  // TODO implement edge cases
  User(std::string username, std::string password) {
    this->username = username;
    this->password = password;
  }

  std::string get_username();
  std::string get_password();
};
} // namespace ToyDB

#endif // !DEBUG
