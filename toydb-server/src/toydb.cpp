#include "../include/toydb.h"

namespace ToyDB {

// FUNCTION: compare_login
//// ARGUMENTS: username (string) and password (string)
//// DESCRIPTION: s/e
//// PRECONDITIONS: ...
//// POSTCONDITIONS: the user is either logged in or the socket is disconnected
//// CAVEATS: ...
//// NOTES: Multiple connections from the same user are possible.
bool ToyDB::compare_login(std::string username, std::string password) {
  bool authsuccess = false;
  for (auto &user : userlist) {
    if (username == user.get_username() && password == user.get_password())
      authsuccess = true;
  }

  return authsuccess;
}

} // namespace ToyDB
