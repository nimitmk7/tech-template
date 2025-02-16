#include "notifier.h"

Notifier::Notifier(int thresh) : threshold(thresh), notified(false) {}

void Notifier::checkAndNotify(int result) {
  if (result > threshold) {
    notified = true;
  }
}

bool Notifier::wasNotified() const { return notified; }