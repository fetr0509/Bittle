cmake_minimum_required(VERSION 3.0)
project(bittle)
enable_testing()

IF (WIN32)
    set(CMAKE_C_FLAGS " -L\"C:/Program\ Files\ \(x86\)/cmocka/lib/\" -Wall -Werror -Wpedantic -std=c11 -lcmocka")
ELSE()
    set(CMAKE_C_FLAGS " -Wall -Werror -Wpedantic -std=c11")
ENDIF()


add_subdirectory(src)
add_subdirectory(test)