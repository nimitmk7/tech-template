# Build the unit test for the Notifier component.
add_executable(unit_test_notifier test_notifier.cpp)
target_link_libraries(unit_test_notifier notifier GTest::Main GTest::GTest)
add_test(NAME unit_test_notifier COMMAND unit_test_notifier)