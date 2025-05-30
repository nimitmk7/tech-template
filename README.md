# **C++ Technology Template Repository**

## Overview
This template serves as a foundation for designing and developing projects in C++, fully equipped for immediate use. It includes features for build management, unit testing, continuous integration, static analysis, code style adherence, and component specification.

## Prerequisites
Before building the project, ensure you have CMake and Ninja installed on your system. These tools are essential for configuring, building, and managing dependencies.

### Installing LLVM/Clang
This project requires the Clang compiler and related LLVM tools for compilation, static analysis, and code coverage:

- **Windows**: Download the LLVM installer from the [LLVM Releases page](https://github.com/llvm/llvm-project/releases). During installation, select the option to add LLVM to your system PATH.
- **macOS**: Install via Homebrew with `brew install llvm`. You may need to update your PATH to use the Homebrew-installed version instead of the system version.
- **Linux**: Install via package manager. For Ubuntu, you can use:
  ```sh
  sudo apt-get install clang clang-tidy llvm
  ```
  
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
This repository includes `vcpkg` as a submodule:
```sh
git clone --recurse-submodules https://github.com/nimitmk7/tech-template.git
```

If you've already cloned the repository without submodules, run:
```sh
git clone https://github.com/nimitmk7/tech-template.git
git submodule update --init --recursive
```

### 2. Bootstrap vcpkg
```sh
cd tech-template/vcpkg
Windows: .\bootstrap-vcpkg.bat
Linux/macOS: ./bootstrap-vcpkg.sh
```

### 3. Configure the Build
```sh
cmake -B build -S . \
 -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake \
-DCMAKE_CXX_COMPILER=clang++ \
-DENABLE_COVERAGE=ON \
-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
-DCMAKE_BUILD_TYPE=Debug \
-G Ninja
```

### 4. Compile the Project
```sh
cd build
ninja
```
### 5. Running Tests Locally
This project uses `gtest_discover_tests` from CMake's GoogleTest module for automatic test discovery.
```sh
cd build
ctest --output-on-failure
```

### 6. Generating a Coverage Report Locally
```sh
llvm-cov gcov $(find . -name "*.gcno")
gcovr -r .. --exclude='.*include/.*\.h'  --html=coverage.html
```

## Continuous Integration (CI) Pipeline
This repository includes a CircleCI pipeline to ensure high code quality and maintainability. The pipeline performs the following tasks:

### CI Features
- **Dependency Management:** Uses `vcpkg` for package management.
- **Build & Compilation:** Uses `clang` and `Ninja` for efficient builds.
- **Unit Testing**: Runs tests via `ctest` using `Google Test`.
- **Static Analysis:** Utilizes `clang-tidy` for code quality checks.
- **Code Coverage:** Uses `llvm-cov gcov` for coverage reports and uploads them to `code-cov`.



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

## Running Static Analysis with Clang-Tidy
```sh
clang-tidy ./src/*.cpp -- -I./include
```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

