cmake_minimum_required(VERSION 4.2)
project(cipher_library)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_library(cipher SHARED
        CaesarCipher.cpp
        VigenereCipher.cpp
        cipher_api.cpp
)
