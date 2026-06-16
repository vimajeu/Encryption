cmake_minimum_required(VERSION 4.2)
project(cipher_cli)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(cipher_app main.cpp)