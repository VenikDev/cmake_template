#include <benchmark/benchmark.h>

#include <cstddef>
#include <string>

static void BM_StringConstruction(benchmark::State& state) {
  for (auto _ : state) {
    std::string value(static_cast<std::size_t>(state.range(0)), 'x');
    benchmark::DoNotOptimize(value);
  }
}

BENCHMARK(BM_StringConstruction)->Range(8, 8 << 10);
