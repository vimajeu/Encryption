//
// Created by ліна on 16.06.2026.
//

#ifndef ENCRYPTION_CIPHER_API_H
#define ENCRYPTION_CIPHER_API_H
#include <cstdint>

#ifdef _WIN32
 #define EXPORT __declspec(dllexport)
#else
 #define EXPORT __attribute__((visibility("default")))
#endif

typedef void* cipher_t;

extern "C" {
      EXPORT cipher_t* cipher_create_caesar (int key);
      EXPORT cipher_t* cipher_create_vigenere(const char* key);

      EXPORT uint8_t* cipher_encrypt(cipher_t* cipher, const uint8_t* data, size_t length, size_t* out_length);
      EXPORT uint8_t* cipher_decrypt(cipher_t* cipher, const uint8_t* data, size_t length, size_t* out_length);

      EXPORT void cipher_destroy(cipher_t* cipher);
      EXPORT void cipher_free (uint8_t* data);
}

#endif //ENCRYPTION_CIPHER_API_H
