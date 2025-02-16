#include <cassert>
#include <iostream>

#include "notifier.h"

void testNotifier() {
  Notifier notifier(10);

  notifier.checkAndNotify(5);
  assert(!notifier.wasNotified());

  notifier.checkAndNotify(15);
  assert(notifier.wasNotified());
}

int main() {
  testNotifier();
  std::cout << "All tests passed!" << std::endl;
  return 0;
}