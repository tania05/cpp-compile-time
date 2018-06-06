cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(cpp_compile_time LANGUAGES CXX)

add_executable(test_cexpr_basic_string app/test_cexpr_basic_string.cpp include/ra/cexpr_basic_string)
#add_executable(test_mandelbrot app/test_mandelbrot.cpp include/ra/mandelbrot.hpp)
add_executable(test_cexpr_math app/test_cexpr_math.cpp include/ra/cexpr_math.hpp)
#add_executable(test_biquad_filter app/test_biquad_filter.cpp include/ra/biquad_filter.hpp)

target_include_directories(test_cexpr_basic_string PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

#target_include_directories(test_mandelbrot PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

target_include_directories(test_cexpr_math PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

find_package(Boost REQUIRED COMPONENTS)

target_link_libraries(test_cexpr_math PUBLIC ${Boost_LIBRARIES})

target_include_directories(test_cexpr_math PUBLIC ${Boost_INCLUDE_DIRS})

#target_include_directories(test_biquad_filter PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fconstexpr-steps=10000000")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)