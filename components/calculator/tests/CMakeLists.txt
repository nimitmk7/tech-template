# Build the unit test for the Calculator component.
add_executable(unit_test_calculator test_calculator.cpp)
target_link_libraries(unit_test_calculator calculator GTest::Main GTest::GTest)
add_test(NAME unit_test_calculator COMMAND unit_test_calculator)