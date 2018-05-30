cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(cpp_compile_time LANGUAGES CXX)

add_executable(test_random app/test_random.cpp lib/random.cpp include/ra/random.hpp)
add_executable(test_rational app/test_rational.cpp include/ra/rational.hpp)

target_include_directories(test_random PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

target_include_directories(test_rational PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

