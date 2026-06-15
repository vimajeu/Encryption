cmake_minimum_required(VERSION 4.2)
project(Encryption)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Encryption
        CaesarCipher.cpp
        CaesarCipher.h
        Cipher.h
        VigenereCipher.cpp
        VigenereCipher.h)
