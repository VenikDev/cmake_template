find_package(benchmark CONFIG REQUIRED)

add_executable(cmake_template_benchmarks main.cpp example_benchmark.cpp)
target_link_libraries(cmake_template_benchmarks PRIVATE benchmark::benchmark)
add_custom_command(
  TARGET cmake_template_benchmarks
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_RUNTIME_DLLS:cmake_template_benchmarks>
          $<TARGET_FILE_DIR:cmake_template_benchmarks>
  COMMAND_EXPAND_LISTS
  VERBATIM
)
