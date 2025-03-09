cmake_minimum_required(VERSION 3.10)
# Add vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file"
)

project(example)

cmake_policy(SET CMP0111 NEW)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add after CMAKE_CXX_STANDARD
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

# Add code coverage flags
option(ENABLE_COVERAGE "Enable coverage reporting for tests" OFF)

#Function to apply coverage only to test targets
function(enable_coverage target)
  if(ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
     message(STATUS "Enabling gcov-compatible coverage for target: ${target}")
      target_compile_options(${target} PRIVATE --coverage)
      target_link_options(${target} PRIVATE --coverage)
    endif()
  endif()
endfunction()

# Find GTest package (vcpkg will provide this)
find_package(GTest CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories for each component.
add_subdirectory(src/calculator)
add_subdirectory(src/logger)
add_subdirectory(src/notifier)

# Main executable using main.cpp.
add_executable(example main.cpp)
target_link_libraries(example
    PRIVATE
        calculator
        logger
        notifier
)

# Enable testing.
enable_testing()
set(CTEST_OUTPUT_ON_FAILURE ON)

# Add unit tests from each component
add_subdirectory(src/calculator/tests ${CMAKE_BINARY_DIR}/src/calculator/tests_bin)
add_subdirectory(src/logger/tests ${CMAKE_BINARY_DIR}/src/logger/tests_bin)
add_subdirectory(src/notifier/tests ${CMAKE_BINARY_DIR}/src/notifier/tests_bin)

# Add integration tests with coverage
file(GLOB INTEGRATION_TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/integration/*.cpp")
foreach(TEST_SOURCE ${INTEGRATION_TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})

  # First link to components
  target_link_libraries(${TEST_NAME}
    PRIVATE
      calculator
      logger
      notifier
  )

  # Then link to GTest
  target_link_libraries(${TEST_NAME}
    PRIVATE
      GTest::gtest
      GTest::gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(${TEST_NAME})
  enable_coverage(${TEST_NAME})
endforeach()

# Add end-to-end tests
file(GLOB E2E_TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/e2e/*.cpp")
foreach(TEST_SOURCE ${E2E_TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})

  # First link to components
  target_link_libraries(${TEST_NAME}
    PRIVATE
      calculator
      logger
      notifier
  )
  target_link_libraries(${TEST_NAME}
    PRIVATE
      GTest::gtest
      GTest::gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(${TEST_NAME})
  enable_coverage(${TEST_NAME})
endforeach()