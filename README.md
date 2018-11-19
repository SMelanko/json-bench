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

```bash
Run on (4 X 3600 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 256K (x4)
  L3 Unified 6144K (x1)
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
-----------------------------------------------------------------------
Benchmark                                Time           CPU Iterations
-----------------------------------------------------------------------
NlCreateJson/iterations:1000000       3103 ns       3102 ns    1000000   4.91966MB/s   314.858k items/s
NlFromJson/iterations:1000000         3274 ns       3274 ns    1000000
NlToJson/iterations:1000000            942 ns        941 ns    1000000
NlStringify/iterations:1000000        2124 ns       2124 ns    1000000
```
