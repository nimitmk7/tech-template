# Build the unit test for the Notifier component.
# set(GTEST_INCLUDE_DIR "/usr/include")
# set(GTEST_LIBRARY "/usr/lib/libgtest.a")
# set(GTEST_MAIN_LIBRARY "/usr/lib/libgtest_main.a")
# add_executable(unit_test_notifier test_notifier.cpp)
# target_link_libraries(unit_test_notifier notifier GTest::Main GTest::GTest)
# add_test(NAME unit_test_notifier COMMAND unit_test_notifier)

add_executable(unit_test_notifier test_notifier.cpp)
target_link_libraries(unit_test_notifier
  PRIVATE
    notifier
    GTest::gtest
    GTest::gtest_main
)
add_test(NAME unit_test_notifier COMMAND unit_test_notifier)