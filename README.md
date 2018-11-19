# JSON Geek Benchmark

[JSON for Modern C++](https://github.com/nlohmann/json) vs [RapidJSON](http://rapidjson.org)

```bash
Run on (8 X 2300 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 6291K (x1)

-----------------------------------------------------------------------
Benchmark                                Time           CPU Iterations
-----------------------------------------------------------------------

NlCreateJson/iterations:1000000       6159 ns       6122 ns    1000000   2.49253MB/s   159.522k items/s
NlFromJson/iterations:1000000         6538 ns       6517 ns    1000000
NlToJson/iterations:1000000           4603 ns       4592 ns    1000000
NlStringify/iterations:1000000        6325 ns       6309 ns    1000000

RaCreateJson/iterations:1000000       1323 ns       1320 ns    1000000   69.3403MB/s    739.63k items/s
RaFromJson/iterations:1000000         1640 ns       1636 ns    1000000
RaToJson/iterations:1000000            390 ns        389 ns    1000000
RaStringify/iterations:1000000        1501 ns       1499 ns    1000000
```
