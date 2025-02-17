# Build the unit test for the Calculator component.
set(GTEST_INCLUDE_DIR "/usr/include")
set(GTEST_LIBRARY "/usr/lib/libgtest.a")
set(GTEST_MAIN_LIBRARY "/usr/lib/libgtest_main.a")
add_executable(unit_test_calculator test_calculator.cpp)
target_link_libraries(unit_test_calculator calculator GTest::Main GTest::GTest)
add_test(NAME unit_test_calculator COMMAND unit_test_calculator)