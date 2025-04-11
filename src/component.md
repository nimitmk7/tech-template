# Component Documentation

This document defines the structure, naming conventions, and guidelines for components in this repository. Components are self-contained modules that encapsulate specific functionality behind a clear, minimal interface. Following these guidelines ensures that our components are easy to understand, maintain, and test while hiding internal complexity.

---

## 1. Component Structure

Each component should be organized within its own subdirectory under the `src` directory.

- **Namespace:**
  All entities (classes, functions, constants) within a component must be defined in a namespace named after the `tt::component`. The namespace should use lowercase letters with words separated by underscores (e.g., `tt::calculator`).

- **Directory Structure:**
  The component’s header and implementation files should reside in a subdirectory whose name matches the component. For example, for a component named **Calculator**, the structure should be:
```
src/
    └── calculator/
        ├── Calculator.cpp
        ├── include/tt/
                  └──calculator/
                              └──Calculator.h
        └── tests/  # unit tests for the component
              
```

- **Header Files:**
Header files should be named after the classes or functionalities they declare and placed within the component's directory (e.g., `src/calculator/include/tt/calculator/Calculator.h`).

- **Implementation Files:**
Implementation files (e.g., `.cpp` files) should correspond to their header files and be placed within the same component directory (e.g., `src/calculator/Calculator.cpp`).

---

## 2. Naming Conventions

- **Namespaces:** Use lowercase letters with words separated by underscores.
*Example:* `calculator`, `logger`, `notifier`

- **Classes/Structs:** Use PascalCase.
*Example:* `Calculator`, `Logger`, `Notifier`

- **Functions/Variables:** Use camelCase.
*Example:* `add`, `subtract`, `logOperation`

---

## 3. Documentation Guidelines

- **Component-Level Documentation:**
Each component should have a leading comment block (typically in its main header file) that describes its purpose and main functionalities.

- **Public Interface Documentation:**
Public classes, methods, and functions must be documented in the header files. Documentation should include:
  - A brief description of what the method or class does.
  - Descriptions of parameters.
  - The return value.
  - Any exceptions thrown.

- **Design Intent:**
Document design decisions that hide internal complexity and promote modularity. This allows users of the component to interact with it through a simple, clear interface without needing to know internal details.

---

## 4. Consistency and Isolation

- **Consistency:**
Ensure that naming, file structure, and documentation are consistent within and across components to improve readability and maintainability.

- **Isolation:**
Design components to minimize dependencies on other components. Use forward declarations and abstract interfaces where possible to reduce coupling.

---

## 5. Testing

- Each component must have corresponding unit tests.
- Create a `tests` subdirectory within each component’s directory (e.g., `src/calculator/tests/`).
- Test files should follow the same naming conventions and aim for comprehensive coverage of the component's functionality.
- Integration and End-to-End Tests must be in the root test directory (e.g., `~/tests/e2e/`).

---

## 6. Example: Calculator Component

Below is an example of how the Calculator component might be structured and documented.

### Example Header File: `src/calculator/include/tt/calculator/Calculator.h`

```cpp
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

```

### Example Implementation File: `src/calculator/Calculator.cpp`

```cpp
#include <tt/calculator/Calculator.h>

namespace tt::calculator {

int Calculator::add(int a, int b) { return a + b; }

int Calculator::subtract(int a, int b) { return a - b; }

int Calculator::multiply(int a, int b) { return a * b; }

int Calculator::divide(int a, int b) {
  if (b == 0) {
    throw std::invalid_argument("Division by zero");
  }
  return a / b;
}

}  // namespace tt::calculator

```

## Components in this Repository

### Calculator
- **Purpose:** Performs basic arithmetic operations.
- **Interface:**
  - `int add(int a, int b)`
  - `int subtract(int a, int b)`
  - `int multiply(int a, int b)`
  - `int divide(int a, int b)` (throws an exception on division by zero)


### Logger
- **Purpose:** Records operations performed by Calculator.
- **Interface:**
  - `void log(const char* operation)`
  - `const std::vector<const char*>& getLogs() const`

### Notifier
- **Purpose:** Monitors calculation results and triggers notifications if a result exceeds a predefined threshold.
- **Interface:**
  - `void checkAndNotify(int result)`
  - `bool wasNotified() const`
