#pragma once

#include "Bench.h"
#include "Data.h"

// https://github.com/Tencent/rapidjson
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
namespace ra = rapidjson;

#if 0
struct UserInfoRa {
    int _id;
    std::string _email;
    std::string _password;
    bool _isActive;
    double _balance;
    Timestamp _lastLogin;
    Timestamp _createdAt;

    template <typename Writer>
    void Serialize(Writer& w) const {
        w.StartObject();
        w.String("id");
        w.Int(_id);
        w.String("email");
        w.String(_email.c_str(), static_cast<ra::SizeType>(_email.length()));
        w.String("password");
        w.String(_password.c_str(), static_cast<ra::SizeType>(_password.length()));
        w.String("isActive");
        w.Bool(_isActive);
        w.String("balance");
        w.Double(_balance);
        w.String("lastLogin");
        w.String(_lastLogin.c_str(), static_cast<ra::SizeType>(_lastLogin.length()));
        w.String("createdAt");
        w.String(_createdAt.c_str(), static_cast<ra::SizeType>(_createdAt.length()));
        w.EndObject();
    }

    static UserInfoRa fromJson(const std::string& str) {
        ra::Document doc;
        doc.Parse(str.c_str());

        return fromJson(doc);
    }

    static UserInfoRa fromJson(const ra::Value& doc) {
        UserInfoRa user;
        user._id = doc["id"].GetInt();
        user._email = doc["email"].GetString();
        user._password = doc["password"].GetString();
        user._isActive = doc["isActive"].GetBool();
        user._balance = doc["balance"].GetDouble();
        user._lastLogin = doc["lastLogin"].GetString();
        user._createdAt = doc["createdAt"].GetString();
        return user;
    }

    std::string toJson() const {
        ra::StringBuffer sb;
        ra::Writer<ra::StringBuffer> w{ sb };
        Serialize(w);
        return sb.GetString();
    }
};

static void RaFromJson(bench::State& state) {
    for (auto _ : state) {
        UserInfoRa user = UserInfoRa::fromJson(test::createUserStr());
    }
}
BENCH(RaFromJson);

static void RaStringify(benchmark::State& state) {
    for (auto _ : state) {
        const UserInfoRa user {
            12345,
            "j.statham@mail.com",
            "c0535e4be2b79ffd93291305436bf889314e4a3faec05ecffcbb7df31ad9e51a",
            true,
            123.45,
            "2018-10-11",
            "2018-10-10"
        };
        const std::string userJsonStr = user.toJson();
    }
}
BENCH(RaStringify);
#endif
