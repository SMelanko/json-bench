#pragma once

#include <string>

using Bool = bool;
using Double = double;
using Id = int;
using String = std::string;
using Timestamp = std::string;

namespace data {

struct UserInfo {
    Id _id;
    String _email;
    String _password;
    Bool _isActive;
    Double _balance;
    Timestamp _lastLogin;
    Timestamp _createdAt;
};

UserInfo CreateUser();
std::string CreateUserStr();

} // namespace data
