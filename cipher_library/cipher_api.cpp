//
// Created by ліна on 16.06.2026.
//

#include "../cipher_api.h"
#include "Cipher.h"
#include "CaesarCipher.h"
#include "../VigenereCipher.h"
#include <cstring>

cipher_t* cipher_create_caesar (int key) {
    CaesarCipher* ciph = new CaesarCipher(key);
    cipher_t* handle = new cipher_t;
    *handle = static_cast<void*>(ciph);
    return handle;
}

cipher_t* cipher_create_vigenere(const char* key) {
    VigenereCipher* ciph = new VigenereCipher(std::string(key));
    cipher_t* handle = new cipher_t;
    *handle = static_cast<void*>(ciph);
    return handle;
}

char* cipher_encrypt(cipher_t* cipher, const char* text) {
    Cipher* ciph = static_cast<Cipher *>(*cipher);
    std::string str_result = ciph->encrypt(std::string(text));
    char* result = new char[str_result.length() + 1];
    std::strcpy(result, str_result.c_str());
    return result;
}

char* cipher_decrypt(cipher_t* cipher, const char* text) {
    Cipher* ciph = static_cast<Cipher *>(*cipher);
    std::string str_result = ciph->decrypt(std::string(text));
    char* result = new char[str_result.length() + 1];
    std::strcpy(result, str_result.c_str());
    return result;
}

void cipher_destroy(cipher_t* cipher) {
    Cipher* real_cipher = static_cast<Cipher *>(*cipher);
    delete real_cipher;
    delete cipher;
}

void cipher_free (char* str) {
    delete[] str;
}