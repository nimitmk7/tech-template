#include <cassert>
#include <iostream>

#include "calculator.h"
#include "logger.h"
#include "notifier.h"

void testEndToEnd() {
  // Initialize components
  Calculator calc;
  Logger logger;
  Notifier notifier(10);  // Threshold set to 10

  // Perform calculations
  int result1 = calc.add(5, 6);       // Should be 11
  int result2 = calc.multiply(2, 3);  // Should be 6

  // Log operations
  logger.log("Addition: 5 + 6");
  logger.log("Multiplication: 2 * 3");

  // Check if notifications are triggered
  notifier.checkAndNotify(result1);  // Should trigger notification
  notifier.checkAndNotify(result2);  // Should NOT trigger notification

  // Assertions
  assert(result1 == 11);
  assert(result2 == 6);

  // Retrieve logs
  const std::vector<std::string>& logs = logger.getLogs();
  assert(logs.size() == 2);
  assert(logs[0] == "Addition: 5 + 6");
  assert(logs[1] == "Multiplication: 2 * 3");

  assert(notifier.wasNotified() == true);  // Notification should be triggered

  std::cout << "End-to-End Test Passed!" << std::endl;
}

int main() {
  testEndToEnd();
  return 0;
}
