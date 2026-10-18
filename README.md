# C++ CMake Project Template

A minimal C++20 project template that uses CMake and Pixi. It includes a sample executable, a GoogleTest smoke test, and a Google Benchmark example; replace these examples with your application code.

## Project structure

- `packages/main/`: sample application (`cmake_template_main`).
- `packages/tests/`: GoogleTest unit-test target (`cmake_template_tests`) with an explicit `main()` in `main.cpp`.
- `packages/benchmarks/`: Google Benchmark executable and example benchmarks (`cmake_template_benchmarks`), with an explicit benchmark `main()` in `main.cpp`. Add benchmark sources here and register them with `BENCHMARK(...)`.
- `CMakeLists.txt` and `CMakePresets.json`: root CMake configuration and Windows Debug/Release presets.
- `pixi.toml` and `pixi.lock`: project dependencies, development tasks, and locked package versions.

## Prerequisites

Install [Pixi](https://pixi.sh/latest/installation/). The Pixi environment installs the CMake/Ninja toolchain, GoogleTest, and Google Benchmark from the `conda-forge` channel specified in `pixi.toml`.

## Install, build, test, and run

From the repository root, install the locked dependencies and run the application and tests:

```sh
pixi install --locked
pixi run run
pixi run test-all
```

Build or test a single configuration with `pixi run build-debug` / `pixi run test-debug` or `pixi run build-release` / `pixi run test-release`. Build both configurations with `pixi run build-all` and run the tests in both with `pixi run test-all`.

Run the sample Google Benchmark suite in the optimized Release configuration:

```sh
pixi run benchmark
```

The example measures string construction at several sizes. Add benchmark functions to `packages/benchmarks/` and register them with `BENCHMARK(...)`. Both test and benchmark executables copy their required runtime DLLs next to the executable after building, so they can also be launched directly from an IDE. The benchmark executable is built in `_Build/windows-release/`.

Run `pixi run format` to format C++ sources and `pixi run clean` to remove generated build outputs. Pixi environments live in `.pixi/` and CMake build files live in `_Build/` (both are ignored by Git).

## Dependencies and other platforms

Add packages available from the configured Pixi channel to the `[dependencies]` section of `pixi.toml`, then run `pixi install` to resolve the environment and update `pixi.lock`. Search for available packages with `pixi search <package> --platform win-64`. Google Benchmark, for example, is provided by the [`benchmark` package on conda-forge](https://anaconda.org/conda-forge/benchmark). For a library that is not packaged for Pixi, use its official upstream distribution and integrate it through CMake, for example with `find_package()` or `FetchContent`; document and pin the dependency as appropriate for your project.

This template currently targets `win-64` and its CMake presets use Clang with Ninja. To target another operating system, add that platform to `pixi.toml` and provide matching dependencies and CMake presets.
