#include "JsonForModernCppBench.h"

namespace data {

void from_json(const nl::json& j, data::UserInfo& user)
{
    user._id = j["id"].get<Id>();
    user._email = j["email"].get<String>();
    user._password = j["password"].get<String>();
    user._isActive = j["isActive"].get<Bool>();
    user._balance = j["balance"].get<Double>();
    user._lastLogin = j["lastLogin"].get<Timestamp>();
    user._createdAt = j["createdAt"].get<Timestamp>();
}

void to_json(nl::json& j, const data::UserInfo& user)
{
    j = nl::json{
        { "id", user._id },
        { "email", user._email },
        { "password", user._password },
        { "isActive", user._isActive },
        { "balance", user._balance },
        { "lastLogin", user._lastLogin },
        { "createdAt", user._createdAt }
    };
}

} // namespace data

namespace impl {

static nl::json CreateUserJson(const std::string& str)
{
    return nl::json::parse(str);
}

} // namespace impl

void NlCreateJson(benchmark::State& state)
{
    const auto userStr = data::CreateUserStr();
    for (auto _ : state) {
        const auto userJson = impl::CreateUserJson(userStr);
    }
    const auto itemsProcessed = static_cast<int64_t>(state.iterations());
    state.SetItemsProcessed(itemsProcessed);
    state.SetBytesProcessed(itemsProcessed * sizeof(impl::CreateUserJson(userStr)));
}
BENCH(NlCreateJson);

void NlFromJson(benchmark::State& state)
{
    const auto userStr = data::CreateUserStr();
    for (auto _ : state) {
        const data::UserInfo user = impl::CreateUserJson(userStr);
    }
}
BENCH(NlFromJson);

void NlToJson(benchmark::State& state)
{
    for (auto _ : state) {
        const nl::json userJson = data::CreateUser();
    }
}
BENCH(NlToJson);

void NlStringify(bench::State& state)
{
    for (auto _ : state) {
        const nl::json userJson = data::CreateUser();
        const std::string userJsonStr = userJson.dump();
    }
}
BENCH(NlStringify);
