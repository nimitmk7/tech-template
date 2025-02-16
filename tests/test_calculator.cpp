#include <cassert>
#include <iostream>

#include "calculator.h"

void testCalculator() {
  Calculator calc;

  assert(calc.add(2, 3) == 5);
  assert(calc.subtract(5, 3) == 2);
  assert(calc.multiply(4, 3) == 12);
  assert(calc.divide(10, 2) == 5);

  try {
    calc.divide(10, 0);
    assert(false);
  } catch (const std::invalid_argument& e) {
    assert(std::string(e.what()) == "Division by zero");
  }
}