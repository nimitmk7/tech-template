#include <iostream>
using namespace std;

void testCalculator();
void testLogger();
void testNotifier();

int main() {
  testCalculator();
  testLogger();
  testNotifier();

  std::cout << "All unit tests passed!" << std::endl;
  return 0;
}
