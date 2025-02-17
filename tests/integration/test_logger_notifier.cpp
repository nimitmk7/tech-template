#include <string>

#include "Logger.h"
#include "Notifier.h"
#include "gtest/gtest.h"

// A simple mock calculator that always returns a fixed result.
class MockCalculator {
 public:
  int add(int a, int b) {
    return 4;  // Always returns 4
  }
};

TEST(IntegrationTest, LoggerNotifier_MockCalculator) {
  // Create instances of the mock Calculator, Logger, and Notifier with a
  // threshold of 5.
  MockCalculator mockCalc;
  logger::Logger log;
  notifier::Notifier notify(5);

  // Use the mock calculator to perform an addition.
  int result = mockCalc.add(1, 2);  // Expected result: 4
  std::string logMessage = "Addition: 1 + 2 = " + std::to_string(result);

  // Log the operation.
  log.log(logMessage.c_str());

  // Check with the Notifier.
  notify.checkAndNotify(result);

  // Verify that the Logger captured the correct message.
  const std::vector<std::string>& logs = log.getLogs();
  ASSERT_FALSE(logs.empty());
  EXPECT_EQ(logs.back(), logMessage);

  // Since the result is below the threshold (4 < 5), the Notifier should not
  // trigger.
  EXPECT_FALSE(notify.wasNotified());
}
