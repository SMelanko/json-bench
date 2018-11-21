#include "JsonCppBench.h"

namespace data::json {

data::UserInfo FromJson(const Json::Value& userJson)
{
    data::UserInfo user;
    user._id = userJson["id"].asInt();
    user._email = userJson["email"].asString();
    user._password = userJson["password"].asString();
    user._isActive = userJson["isActive"].asBool();
    user._balance = userJson["balance"].asDouble();
    user._createdAt = userJson["createdAt"].asString();
    user._lastLogin = userJson["_lastLogin"].asString();

    return user;
}

Json::Value ToJson(const data::UserInfo& user)
{
    Json::Value userJson;
    userJson["id"] = user._id;
    userJson["email"] = user._email;
    userJson["password"] = user._password;
    userJson["isActive"] = user._isActive;
    userJson["balance"] = user._balance;
    userJson["createdAt"] = user._createdAt;
    userJson["_lastLogin"] = user._lastLogin;

    return userJson;
}

} // namespace data::json

namespace impl {

static Json::Value CreateUserJson(const std::string& str)
{
    Json::Value root;
    Json::Reader reader;
    reader.parse(str, root);

    return root;
}

[[maybe_unused]] static Json::Value CreateUserJsonV1(const std::string& str)
{
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    Json::Value root;
    std::string error;
    reader->parse(str.c_str(), str.c_str() + str.length(), &root, &error);
    delete reader;

    return root;
}

} // namespace impl

void JcCreateJson(benchmark::State& state)
{
    const auto userStr = data::CreateUserStr();
    for (auto _ : state) {
        const auto userJson = impl::CreateUserJson(userStr);
    }
    const auto itemsProcessed = static_cast<int64_t>(state.iterations());
    state.SetItemsProcessed(itemsProcessed);
    state.SetBytesProcessed(itemsProcessed * sizeof(impl::CreateUserJson(userStr)));
}
BENCH(JcCreateJson);

void JcFromJson(bench::State& state)
{
    const auto userStr = data::CreateUserStr();
    for (auto _ : state) {
        const data::UserInfo user = data::json::FromJson(impl::CreateUserJson(userStr));
    }
}
BENCH(JcFromJson);

void JcToJson(bench::State& state)
{
    const auto user = data::CreateUser();
    for (auto _ : state) {
        const Json::Value userJson = data::json::ToJson(user);
    }
}
BENCH(JcToJson);

void JcStringify(bench::State& state)
{
    const auto user = data::CreateUser();
    for (auto _ : state) {
        const Json::Value userJson = data::json::ToJson(user);
        Json::FastWriter writer;
        const std::string userJsonStr = writer.write(userJson);
    }
}
BENCH(JcStringify);
