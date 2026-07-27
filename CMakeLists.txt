cmake_minimum_required(VERSION 4.0)
project(Tenjin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE TENJIN_SOURCES CONFIGURE_DEPENDS
     src/*.cpp src/*.c src/*.hpp src/*.h
)

add_executable(tenjin ${TENJIN_SOURCES})
