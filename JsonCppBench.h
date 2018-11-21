#pragma once

#include "Bench.h"
#include "Data.h"

#include <json/json.h>

namespace data::json {

data::UserInfo FromJson(const Json::Value& userJson);
Json::Value ToJson(const data::UserInfo& user);

} // namespace data::json

/// Str -> JSON.
void JcCreateJson(bench::State& state);
/// JSON -> C++ struct.
void JcFromJson(bench::State& state);
/// C++ struct -> JSON.
void JcToJson(bench::State& state);
/// C++ struct -> Str.
void JcStringify(bench::State& state);
