find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(cmake_template_tests main.cpp smoke_test.cpp)
target_link_libraries(cmake_template_tests PRIVATE GTest::gtest)
add_custom_command(
  TARGET cmake_template_tests
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_RUNTIME_DLLS:cmake_template_tests>
          $<TARGET_FILE_DIR:cmake_template_tests>
  COMMAND_EXPAND_LISTS
  VERBATIM
)
gtest_discover_tests(cmake_template_tests DISCOVERY_MODE PRE_TEST)
