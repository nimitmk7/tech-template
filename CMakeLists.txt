cmake_minimum_required(VERSION 3.10)
project(example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Add the main executable
add_executable(example main.cpp)

# Enable testing
enable_testing()

file(GLOB TEST_SOURCES "tests/*.cpp")
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})  # Create a separate executable for each test file
  target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_SOURCE_DIR}) # Ensure test files can include project headers
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
