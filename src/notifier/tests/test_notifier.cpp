#include <gtest/gtest.h>
#include <tt/notifier/Notifier.h>

TEST(NotifierTest, CheckNotifications) {
  tt::notifier::Notifier notifier(10);

  notifier.checkAndNotify(5);
  EXPECT_FALSE(notifier.wasNotified());

  notifier.checkAndNotify(15);
  EXPECT_TRUE(notifier.wasNotified());
}
