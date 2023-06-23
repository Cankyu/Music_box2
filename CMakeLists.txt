cmake_minimum_required (VERSION 3.20)
project (Music_Box2)

set (CMAKE_CXX_STANDARD 11)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/test)

add_executable (Music_Box2 src/Music_library.cpp src/main2.cpp)
add_executable (Music_Box2_Test src/Music_library.cpp test/test_main.cpp)


