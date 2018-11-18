#include "Precompiled.h"

#include "Data.h"

namespace data {

UserInfo CreateUser() {
    return UserInfo{
        12345,
        "j.statham@mail.com",
        "c0535e4be2b79ffd93291305436bf889314e4a3faec05ecffcbb7df31ad9e51a",
        true,
        123.45,
        "2018-10-11",
        "2018-10-10"
    };
}

std::string CreateUserStr()
{
    return std::string{ R"(
        {
            "id": 12345,
            "email": "j.statham@mail.com",
            "password": "c0535e4be2b79ffd93291305436bf889314e4a3faec05ecffcbb7df31ad9e51a",
            "isActive": true,
            "balance": 123.45,
            "lastLogin": "2018-10-11",
            "createdAt": "2018-10-10"
        }
    )"};
}

} // namespace data
