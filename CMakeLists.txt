cmake_minimum_required(VERSION 3.10)
project(example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Include the directory containing header files
include_directories(${CMAKE_SOURCE_DIR}/include)


# Collect all source files for core functionality
file(GLOB PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")  # Assuming all core classes are in `src/`
file(GLOB PROJECT_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")  # Assuming headers are in `include/`

# Create a library for the core functionality
add_library(example_lib ${PROJECT_SOURCES}) 

# Main executable
add_executable(example main.cpp)
target_link_libraries(example example_lib)
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Enable testing
enable_testing()

# Collect all test sources
file(GLOB TEST_SOURCES "tests/*.cpp")

# Create test executables
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  
  # Link the test executable with the core library
  target_link_libraries(${TEST_NAME} example_lib)

  # Ensure test files can include project headers
  target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

  # Register test with CTest
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()



