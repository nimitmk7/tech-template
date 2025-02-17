# Component Documentation

This document defines the structure, naming conventions, and guidelines for components in this repository. Components are self-contained modules that encapsulate specific functionality behind a clear, minimal interface. Following these guidelines ensures that our components are easy to understand, maintain, and test while hiding internal complexity.

---

## 1. Component Structure

Each component should be organized within its own subdirectory under the `components` directory.

- **Namespace:**  
  All entities (classes, functions, constants) within a component must be defined in a namespace named after the component. The namespace should use lowercase letters with words separated by underscores (e.g., `calculator`).

- **Directory Structure:**  
  The component’s header and implementation files should reside in a subdirectory whose name matches the component. For example, for a component named **Calculator**, the structure should be:
```
components/
    └── calculator/
        ├── Calculator.h
        ├── Calculator.cpp
        └── tests/         # unit tests for the component
```

- **Header Files:**  
Header files should be named after the classes or functionalities they declare and placed within the component's directory (e.g., `components/calculator/Calculator.h`).

- **Implementation Files:**  
Implementation files (e.g., `.cpp` files) should correspond to their header files and be placed within the same component directory (e.g., `components/calculator/Calculator.cpp`).

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
- Create a `tests` subdirectory within each component’s directory (e.g., `components/calculator/tests/`).
- Test files should follow the same naming conventions and aim for comprehensive coverage of the component's functionality.

---

## 6. Example: Calculator Component

Below is an example of how the Calculator component might be structured and documented.

### Example Header File: `components/calculator/Calculator.h`

```cpp
#ifndef CALCULATOR_H
#define CALCULATOR_H

namespace calculator {

/**
* @brief The Calculator class provides basic arithmetic operations.
*
* This class implements addition, subtraction, multiplication, and division,
* while handling errors such as division by zero.
*/
class Calculator {
public:
  /**
   * @brief Adds two integers.
   * @param a First operand.
   * @param b Second operand.
   * @return The sum of a and b.
   */
  int add(int a, int b);

  /**
   * @brief Subtracts one integer from another.
   * @param a First operand.
   * @param b Second operand.
   * @return The difference (a - b).
   */
  int subtract(int a, int b);

  /**
   * @brief Multiplies two integers.
   * @param a First operand.
   * @param b Second operand.
   * @return The product of a and b.
   */
  int multiply(int a, int b);

  /**
   * @brief Divides one integer by another.
   * @param a Numerator.
   * @param b Denominator (must not be zero).
   * @return The quotient of a divided by b.
   * @throws std::invalid_argument if b is zero.
   */
  int divide(int a, int b);
};

} // namespace calculator

#endif // CALCULATOR_H
```

### Example Implementation File: `components/calculator/Calculator.cpp`

```cpp
#include "Calculator.h"
#include <stdexcept>

namespace calculator {

int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}

int Calculator::multiply(int a, int b) {
    return a * b;
}

int Calculator::divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

}


``` 

## Components in This Repository

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

