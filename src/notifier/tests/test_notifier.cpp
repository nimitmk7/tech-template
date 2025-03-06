#include "Notifier.h"
#include "gtest/gtest.h"

TEST(NotifierTest, CheckNotifications) {
  notifier::Notifier notifier(10);

  notifier.checkAndNotify(5);
  EXPECT_FALSE(notifier.wasNotified());

  notifier.checkAndNotify(15);
  EXPECT_TRUE(notifier.wasNotified());
}
