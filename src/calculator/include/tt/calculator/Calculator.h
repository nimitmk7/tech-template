#pragma once

#include <stdexcept>

namespace tt::calculator {

/**
 * @brief Provides basic arithmetic operations.
 */
class Calculator {
 public:
  /**
   * @brief Adds two integers.
   * @param a First operand.
   * @param b Second operand.
   * @return Sum of a and b.
   */
  int add(int a, int b);

  /**
   * @brief Subtracts the second integer from the first.
   * @param a First operand.
   * @param b Second operand.
   * @return Difference (a - b).
   */
  int subtract(int a, int b);

  /**
   * @brief Multiplies two integers.
   * @param a First operand.
   * @param b Second operand.
   * @return Product of a and b.
   */
  int multiply(int a, int b);

  /**
   * @brief Divides one integer by another.
   * @param a Numerator.
   * @param b Denominator (must not be zero).
   * @return Quotient of a divided by b.
   * @throws std::invalid_argument if b is zero.
   */
  int divide(int a, int b);
};

}  // namespace tt::calculator
