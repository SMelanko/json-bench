#pragma once

#include "Bench.h"
#include "Data.h"

#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
namespace ra = rapidjson;

namespace data {

data::UserInfo FromJson(const ra::Document& userJson);
ra::Document ToJson(const data::UserInfo& user);

} // namespace data

/// Str -> JSON.
void RaCreateJson(bench::State& state);
/// JSON -> C++ struct.
void RaFromJson(bench::State& state);
/// C++ struct -> JSON.
void RaToJson(bench::State& state);
/// C++ struct -> Str.
void RaStringify(bench::State& state);
