# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Add your source files
add_executable(example main.cpp)

# Enable testing
enable_testing()

file(GLOB TEST_SOURCES "tests/*.cpp")
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  target_link_libraries(${TEST_NAME} example GTest::gtest) # Link with your main project AND Google Test
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
