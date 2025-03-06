# src/logger/CMakeLists.txt
add_library(logger Logger.cpp)

target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})