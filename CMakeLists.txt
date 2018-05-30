cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(cpp_compile_time LANGUAGES CXX)

add_executable(test_cexpr_basic_string app/test_cexpr_basic_string.cpp include/ra/cexpr_basic_string app.hpp)
add_executable(test_mandelbrot app/test_mandelbrot.cpp include/ra/mandelbrot.hpp)
add_executable(test_cexpr_math app/test_cexpr_math.cpp include/ra/cexpr_math.hpp)
add_executable(test_biquad_filter app/tet_biquad_filter.cpp include/ra/biquad_filter.hpp)

target_include_directories(test_cexpr_basic_string PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

target_include_directories(test_mandelbrot PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

target_include_directories(test_cexpr_math PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

target_include_directories(test_biquad_filter PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

