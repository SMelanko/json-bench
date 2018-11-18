# JSON Geek Benchmark

[JSON for Modern C++](https://github.com/nlohmann/json) vs [RapidJSON](http://rapidjson.org)

```bash
-------------------------------------------------------------------------
Benchmark                                  Time           CPU Iterations
-------------------------------------------------------------------------
NlCreateJsonV1/iterations:1000000       5859 ns       5848 ns    1000000   2.60903MB/s   166.978k items/s
NlCreateJsonV2/iterations:1000000       1700 ns       1693 ns    1000000   9.01337MB/s   576.855k items/s
NlFromJsonV1/iterations:1000000         6431 ns       6420 ns    1000000
NlFromJsonV2/iterations:1000000         2295 ns       2292 ns    1000000
NlToJson/iterations:1000000             4608 ns       4602 ns    1000000
NlStringify/iterations:1000000          6316 ns       6306 ns    1000000er
```
