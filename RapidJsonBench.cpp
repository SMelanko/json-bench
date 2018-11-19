#include "RapidJsonBench.h"

namespace data {

data::UserInfo FromJson(const ra::Document& userJson)
{
    data::UserInfo user;
    user._id = userJson["id"].GetInt();
    user._email = userJson["email"].GetString();
    user._password = userJson["password"].GetString();
    user._isActive = userJson["isActive"].GetBool();
    user._balance = userJson["balance"].GetDouble();
    user._lastLogin = userJson["lastLogin"].GetString();
    user._createdAt = userJson["createdAt"].GetString();

    return user;
}

ra::Document ToJson(const data::UserInfo& user)
{
    ra::Document doc;
    doc.SetObject();
    // Must pass an allocator when the object may need to allocate memory.
    ra::Document::AllocatorType& allocator = doc.GetAllocator();
    doc.AddMember("id", user._id, allocator);
    doc.AddMember("email", ra::Value{ user._email.c_str(), allocator }.Move(), allocator);
    doc.AddMember("password", ra::Value{ user._password.c_str(), allocator }.Move(), allocator);
    doc.AddMember("isActive", user._isActive, allocator);
    doc.AddMember("balance", user._balance, allocator);
    doc.AddMember("lastLogin", ra::Value{ user._lastLogin.c_str(), allocator }.Move(), allocator);
    doc.AddMember("createdAt", ra::Value{ user._createdAt.c_str(), allocator }.Move(), allocator);

    return doc;
}

} // namespace data

namespace impl {

static ra::Document CreateUserJson(const std::string& userStr)
{
    // Document is the root of a JSON.
    ra::Document doc;
    // Parse a JSON string into DOM.
    doc.Parse(userStr.c_str(), userStr.length());

    return doc;
}

} // namespace impl

void RaCreateJson(benchmark::State& state)
{
    const auto userStr = data::CreateUserStr();
    for (auto _ : state) {
        const auto userJson = impl::CreateUserJson(userStr);
    }
    const auto itemsProcessed = static_cast<int64_t>(state.iterations());
    state.SetItemsProcessed(itemsProcessed);
    state.SetBytesProcessed(itemsProcessed * sizeof(impl::CreateUserJson(userStr)));
}
BENCH(RaCreateJson);

void RaFromJson(bench::State& state)
{
    const auto userStr = data::CreateUserStr();
    for (auto _ : state) {
        const data::UserInfo user = data::FromJson(impl::CreateUserJson(userStr));
    }
}
BENCH(RaFromJson);

void RaToJson(benchmark::State& state)
{
    const auto user = data::CreateUser();
    for (auto _ : state) {
        const ra::Document userJson = data::ToJson(user);
    }
}
BENCH(RaToJson);

void RaStringify(bench::State& state)
{
    const auto user = data::CreateUser();
    for (auto _ : state) {
        const ra::Document userJson = data::ToJson(user);
        ra::StringBuffer buffer;
        ra::Writer<ra::StringBuffer> writer{ buffer };
        userJson.Accept(writer);
        const std::string userJsonStr = buffer.GetString();
    }
}
BENCH(RaStringify);
