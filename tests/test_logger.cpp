#include <cassert>
#include <iostream>

#include "logger.h"

void testLogger() {
  Logger logger;

  logger.log("add");
  logger.log("subtract");

  // Correct type: std::vector<std::string>
  const std::vector<std::string>& logs = logger.getLogs();

  // Check log count
  assert(logs.size() == 2);

  // Check log contents
  assert(logs[0] == "add");
  assert(logs[1] == "subtract");

  std::cout << "Logger Test Passed!" << std::endl;
}

int main() {
  testLogger();
  return 0;
}
