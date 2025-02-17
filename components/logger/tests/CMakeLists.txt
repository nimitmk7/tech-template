# Build the unit test for the Logger component.
add_executable(unit_test_logger test_logger.cpp)
target_link_libraries(unit_test_logger logger GTest::Main GTest::GTest)
add_test(NAME unit_test_logger COMMAND unit_test_logger)