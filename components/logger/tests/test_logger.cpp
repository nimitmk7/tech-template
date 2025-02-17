#include "gtest/gtest.h"
#include "Logger.h"
#include <vector>
#include <string>

TEST(LoggerTest, LogOperations) {
    logger::Logger logger;
    logger.log("add");
    logger.log("subtract");

    const std::vector<std::string>& logs = logger.getLogs();
    ASSERT_EQ(logs.size(), 2);
    EXPECT_EQ(logs[0], "add");
    EXPECT_EQ(logs[1], "subtract");
}
