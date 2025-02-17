# CMake generated Testfile for 
# Source directory: /Users/adi/tech-template
# Build directory: /Users/adi/tech-template/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_calculator_logger "/Users/adi/tech-template/build/test_calculator_logger")
set_tests_properties(test_calculator_logger PROPERTIES  _BACKTRACE_TRIPLES "/Users/adi/tech-template/CMakeLists.txt;32;add_test;/Users/adi/tech-template/CMakeLists.txt;0;")
add_test(test_logger_notifier "/Users/adi/tech-template/build/test_logger_notifier")
set_tests_properties(test_logger_notifier PROPERTIES  _BACKTRACE_TRIPLES "/Users/adi/tech-template/CMakeLists.txt;32;add_test;/Users/adi/tech-template/CMakeLists.txt;0;")
add_test(test_e2e "/Users/adi/tech-template/build/test_e2e")
set_tests_properties(test_e2e PROPERTIES  _BACKTRACE_TRIPLES "/Users/adi/tech-template/CMakeLists.txt;41;add_test;/Users/adi/tech-template/CMakeLists.txt;0;")
subdirs("components/calculator")
subdirs("components/logger")
subdirs("components/notifier")
subdirs("components/calculator/tests_bin")
subdirs("components/logger/tests_bin")
subdirs("components/notifier/tests_bin")
