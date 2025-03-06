# Build the unit test for the Calculator component.
# add_executable(unit_test_calculator test_calculator.cpp)
# target_link_libraries(unit_test_calculator calculator GTest::Main GTest::GTest)
# add_test(NAME unit_test_calculator COMMAND unit_test_calculator)

add_executable(unit_test_calculator test_calculator.cpp)
target_link_libraries(unit_test_calculator
  PRIVATE
    calculator
    GTest::gtest
    GTest::gtest_main
)

if(ENABLE_COVERAGE)
  target_compile_options(unit_test_calculator PRIVATE -fprofile-instr-generate -fcoverage-mapping)
  target_link_options(unit_test_calculator PRIVATE -fprofile-instr-generate -fcoverage-mapping)
endif()

# add_test(NAME unit_test_calculator COMMAND unit_test_calculator)
include(GoogleTest)
gtest_discover_tests(unit_test_calculator)