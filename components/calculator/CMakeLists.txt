# components/calculator/CMakeLists.txt
add_library(calculator Calculator.cpp)

# Set the include directory for this component so that users of the library 
#can include its headers using, for example, #include "Calculator.h"
target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

