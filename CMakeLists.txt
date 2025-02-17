cmake_minimum_required(VERSION 3.10)
project(example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

set(GTEST_INCLUDE_DIR "/usr/include")
set(GTEST_LIBRARY "/usr/lib/libgtest.a")
set(GTEST_MAIN_LIBRARY "/usr/lib/libgtest_main.a")
find_package(GTest REQUIRED)

option(ENABLE_COVERAGE "Enable coverage reporting" ON)

if(ENABLE_COVERAGE)
  # These flags work for gcc and clang (with gcov support).
  # For clang you might also need -fprofile-instr-generate -fcoverage-mapping
  add_compile_options(--coverage -fprofile-arcs -ftest-coverage)
  add_link_options(--coverage -fprofile-arcs -ftest-coverage)
endif()


# Add subdirectories for each component.
add_subdirectory(components/calculator)
add_subdirectory(components/logger)
add_subdirectory(components/notifier)

# Main executable using main.cpp.
add_executable(example main.cpp)
target_link_libraries(example calculator logger notifier)

# Enable testing.
enable_testing()

# Add unit tests from each component's tests directory with unique binary directories.
add_subdirectory(components/calculator/tests ${CMAKE_BINARY_DIR}/components/calculator/tests_bin)
add_subdirectory(components/logger/tests ${CMAKE_BINARY_DIR}/components/logger/tests_bin)
add_subdirectory(components/notifier/tests ${CMAKE_BINARY_DIR}/components/notifier/tests_bin)

# Add integration tests (assuming they reside in tests/integration)
file(GLOB INTEGRATION_TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/integration/*.cpp")
foreach(TEST_SOURCE ${INTEGRATION_TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  target_link_libraries(${TEST_NAME} calculator logger notifier GTest::Main GTest::GTest)
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()



# Add end-to-end tests (assuming they reside in tests/e2e)
file(GLOB E2E_TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/e2e/*.cpp")
foreach(TEST_SOURCE ${E2E_TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  target_link_libraries(${TEST_NAME} calculator logger notifier GTest::Main GTest::GTest)
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()