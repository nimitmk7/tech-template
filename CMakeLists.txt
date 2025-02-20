cmake_minimum_required(VERSION 3.10)
project(example)

cmake_policy(SET CMP0111 NEW)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.14.0
)

# Force using the fetched version instead of system version
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

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
  target_link_libraries(${TEST_NAME}
    PRIVATE
      calculator
      logger
      notifier
      GTest::gtest
      GTest::gtest_main
  )
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

# Add end-to-end tests (assuming they reside in tests/e2e)
file(GLOB E2E_TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/e2e/*.cpp")
foreach(TEST_SOURCE ${E2E_TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  target_link_libraries(${TEST_NAME}
    PRIVATE
      calculator
      logger
      notifier
      GTest::gtest
      GTest::gtest_main
  )
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()