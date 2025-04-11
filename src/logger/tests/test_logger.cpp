#include <gtest/gtest.h>
#include <tt/logger/Logger.h>

TEST(LoggerTest, LogOperations) {
  tt::logger::Logger logger;
  logger.log("add");
  logger.log("subtract");

  const std::vector<std::string>& logs = logger.getLogs();
  ASSERT_EQ(logs.size(), 2);
  EXPECT_EQ(logs[0], "add");
  EXPECT_EQ(logs[1], "subtract");
}
