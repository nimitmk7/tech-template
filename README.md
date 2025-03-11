# **C++ Technology Template Repository**
### Overview:
This template serves as a foundation for designing and developing projects in C++, fully equipped for immediate use. It includes features for build management, unit testing, continuous integration, static analysis, code style adherence, and component specification.

Components:  
---
Calculator - performs basic arithmetic operations  
Logger - records operations performed by calculator  
Notifier - sends an alert when the result exceeds a given threshold.  

Tests:
---
#### A CI pipeline executes the tests.
### Unit Tests  
Calculator - Test addition, subtraction, and multiplication.  
Logger - Test that operations are logged correctly.  
Notifier - Test that notifications are sent when threshold is exceeded  
### Integration Tests  
Calculator  Logger (Mock Notifier)  
Logger  Notifier (Mock Calculator)  
### End-to-End Test  
Perform a calculation, log it, and send a notification when the threshold is exceeded.  

## Static Code Analysis with Clang Static Analyzer

The Clang Static Analyzer is a powerful tool for detecting bugs, memory leaks, and other potential issues in C and C++ code. It analyzes the code at compile time, without needing to execute it.

### Running the Clang Static Analyzer

To run the Clang Static Analyzer on this project, please follow these steps. Note that on Windows, these steps should be performed in Git Bash to ensure compatibility with Unix-like commands and behaviors used by `scan-build`.

#### Run the Analyzer

In your `build` directory, execute the Clang Static Analyzer using `scan-build`:

```sh
scan-build cmake --build .
```

Please ensure to format your code using the provided script before submitting a pull request. This helps to maintain a consistent codebase and simplifies the review process.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.