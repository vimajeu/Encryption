//
// Created by ліна on 16.06.2026.
//

#include "cipher_api.h"
#include "Cipher.h"
#include "CaesarCipher.h"
#include "VigenereCipher.h"
#include <cstring>

extern "C" {
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

uint8_t* cipher_encrypt(cipher_t* cipher, const uint8_t* data, size_t length, size_t* out_length) {
    Cipher* ciph = static_cast<Cipher*>(*cipher);
    std::vector<uint8_t> input(data, data + length);
    std::vector<uint8_t> result = ciph->encrypt(input);

    *out_length = result.size();
    uint8_t* out = new uint8_t[result.size()];
    std::memcpy(out, result.data(), result.size());
    return out;
}

uint8_t* cipher_decrypt(cipher_t* cipher, const uint8_t* data, size_t length, size_t* out_length) {
    Cipher* ciph = static_cast<Cipher*>(*cipher);
    std::vector<uint8_t> input(data, data + length);
    std::vector<uint8_t> result = ciph->decrypt(input);

    *out_length = result.size();
    uint8_t* out = new uint8_t[result.size()];
    std::memcpy(out, result.data(), result.size());
    return out;
}

void cipher_destroy(cipher_t* cipher) {
    Cipher* real_cipher = static_cast<Cipher *>(*cipher);
    delete real_cipher;
    delete cipher;
}

void cipher_free (uint8_t* data) {
    delete[] data;
}
}