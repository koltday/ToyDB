#include "../include/user.h"

namespace ToyDB {
std::string ToyDB::User::get_username() { return this->username; }

std::string ToyDB::User::get_password() { return this->password; }
} // namespace ToyDB
