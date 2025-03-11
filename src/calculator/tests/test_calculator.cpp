#include <gtest/gtest.h>
#include <tt/calculator/Calculator.h>

#include <stdexcept>
#include <string>

TEST(CalculatorTest, BasicOperations) {
  tt::calculator::Calculator calc;
  EXPECT_EQ(calc.add(2, 3), 5);
  EXPECT_EQ(calc.subtract(5, 3), 2);
  EXPECT_EQ(calc.multiply(4, 3), 12);
  EXPECT_EQ(calc.divide(10, 2), 5);
}

TEST(CalculatorTest, DivisionByZeroThrows) {
  tt::calculator::Calculator calc;
  EXPECT_THROW({ calc.divide(10, 0); }, std::invalid_argument);
}

TEST(CalculatorTest, DeliberateFailure) {
  tt::calculator::Calculator calc;
  
  // This test will intentionally fail
  EXPECT_EQ(calc.add(2, 3), 10) << "Deliberate failure: 2 + 3 should be 5, but we expect 10!";
}
