#include "user.h"
#include <string>
#include <vector>

using ToyDB::User;

#ifndef __TOYDB_H__
#define __TOYDB_H__

namespace ToyDB {
class ToyDB {
public:
  std::vector<User> userlist;

  ToyDB() {
    User u("root", "password");
    User p("nonroot", "nonpassword");
    userlist.push_back(u);
    userlist.push_back(p);
  }

  ~ToyDB() { userlist.clear(); }

  bool compare_login(std::string username, std::string password);
  void start_server();
};
} // namespace ToyDB

#endif
