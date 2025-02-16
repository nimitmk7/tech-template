#include <cassert>
#include <iostream>

#include "logger.h"

void testLogger() {
  Logger logger;

  logger.log("add");
  logger.log("subtract");

  const std::vector<const char*>& logs = logger.getLogs();
  assert(logs.size() == 2);
  assert(std::string(logs[0]) == "add");
  assert(std::string(logs[1]) == "subtract");
}

int main() {
  testLogger();
  std::cout << "All tests passed!" << std::endl;
  return 0;
}