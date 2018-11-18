#pragma once

#include "Bench.h"
#include "Data.h"

#include <nlohmann/json.hpp>
namespace nl = nlohmann;

namespace data {

void from_json(const nl::json& j, data::UserInfo& user);
void to_json(nl::json& j, const data::UserInfo& user);

} // namespace data

/// Str -> JSON.
void NlCreateJson(bench::State& state);
/// JSON -> C++ struct.
void NlFromJson(bench::State& state);
/// C++ struct -> JSON.
void NlToJson(bench::State& state);
/// C++ struct -> Str.
void NlStringify(bench::State& state);
