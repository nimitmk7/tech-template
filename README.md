# **C++ Technology Template Repository**

## Overview
This template serves as a foundation for designing and developing projects in C++, fully equipped for immediate use. It includes features for build management, unit testing, continuous integration, static analysis, code style adherence, and component specification.

## Prerequisites
Before building the project, ensure you have CMake and Ninja installed on your system. These tools are essential for configuring, building, and managing dependencies.

### Installing CMake
CMake is a cross-platform build system generator. To install CMake:

- **Windows**: Download the installer from the [CMake Downloads page](https://cmake.org/download/) and follow the installation prompts. Ensure you select the option to add CMake to your system PATH.
- **macOS**: Use Homebrew by running `brew install cmake` in the terminal, or download the macOS binary from the CMake website.
- **Linux**: Most distributions include CMake in their package managers. For example, on Ubuntu, you can install it with `sudo apt-get install cmake`.

### Installing Ninja
Ninja is a small build system focused on speed. To install Ninja:

- **Windows**: Download the latest binary from Ninja's [GitHub releases page](https://github.com/ninja-build/ninja/releases). Extract the executable and add its location to your system's PATH.
- **macOS and Linux**: Ninja can be installed through Homebrew on macOS (`brew install ninja`) or through the package manager on Linux (for example, `sudo apt-get install ninja-build` on Ubuntu).

## Project Setup and Build Instructions
This project uses CMake as its build system, with Ninja as the preferred generator for efficiency and speed. Follow these steps to build the project:

### 1. Clone the Repository
```sh
 git clone --recurse-submodules <repository_url>
 cd <repository>
```

### 2. Configure the Build
```sh
mkdir build && cd build
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake ..
```

### 3. Compile the Project
```sh
cmake --build .
```

### 4. Run Tests
```sh
ctest --output-on-failure
```

## Continuous Integration (CI) Pipeline
This repository includes a CircleCI pipeline to ensure high code quality and maintainability. The pipeline performs the following tasks:

### CI Features
- **Dependency Management:** Uses `vcpkg` for package management.
- **Docker Integration:** Secure login and image management via DockerHub.
- **Build & Compilation:** Uses `clang++` and `Ninja` for efficient builds.
- **Unit Testing**: Runs tests via `ctest` using `Google Test`.
- **Static Analysis:** Utilizes `clang-tidy` for code quality checks.
- **Code Coverage:** Uses `llvm-cov` for coverage reports and uploads them to Codecov.

### Running CI Locally
You can run parts of the CI pipeline locally before pushing changes to avoid breaking builds.

#### Running Tests Locally
```sh
cd build
ectest --output-on-failure
```

#### Running Static Analysis with Clang-Tidy
```sh
clang-tidy ./src/*.cpp -- -I./include
```

#### Generating a Coverage Report
```sh
llvm-cov gcov $(find . -name "*.gcno")
```

## Code Formatting
Maintaining code consistency is crucial to this project. We enforce strict formatting guidelines using `clang-format`.

### Apply Formatting
- **Windows:**
  ```cmd
  .\scripts\format-code.cmd
  ```
- **Linux/macOS:**
  ```sh
  find ./src -iname '*.h' -o -iname '*.cpp' -exec clang-format -i {} +
  ```

### Check Formatting Without Applying Changes
```sh
find ./src -iname '*.h' -o -iname '*.cpp' -exec clang-format -n -Werror {} +
```

## Static Code Analysis with Clang Static Analyzer
 
 The Clang Static Analyzer is a powerful tool for detecting bugs, memory leaks, and other potential issues in C and C++ code. It analyzes the code at compile time, without needing to execute it.
 
 ### Running the Clang Static Analyzer
 
 To run the Clang Static Analyzer on this project, please follow these steps. Note that on Windows, these steps should be performed in Git Bash to ensure compatibility with Unix-like commands and behaviors used by `scan-build`.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

