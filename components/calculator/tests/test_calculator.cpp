#include "gtest/gtest.h"
#include "Calculator.h"
#include <stdexcept>
#include <string>

TEST(CalculatorTest, BasicOperations) {
    calculator::Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.subtract(5, 3), 2);
    EXPECT_EQ(calc.multiply(4, 3), 12);
    EXPECT_EQ(calc.divide(10, 2), 5);
}

TEST(CalculatorTest, DivisionByZeroThrows) {
    calculator::Calculator calc;
    EXPECT_THROW({
        calc.divide(10, 0);
    }, std::invalid_argument);
}
