# Build the unit test for the Logger component.
set(GTEST_INCLUDE_DIR "/usr/include")
set(GTEST_LIBRARY "/usr/lib/libgtest.a")
set(GTEST_MAIN_LIBRARY "/usr/lib/libgtest_main.a")
add_executable(unit_test_logger test_logger.cpp)
target_link_libraries(unit_test_logger logger GTest::Main GTest::GTest)
add_test(NAME unit_test_logger COMMAND unit_test_logger)