//
// Created by ліна on 16.06.2026.
//

#ifndef ENCRYPTION_CIPHER_API_H
#define ENCRYPTION_CIPHER_API_H

typedef void* cipher_t;

/* Factory — creates the cipher object and returns an opaque handle */
cipher_t* cipher_create_caesar (int key);
cipher_t* cipher_create_vigenere(const char* key);
/* Operations — behave differently depending on which cipher was
created */
char* cipher_encrypt(cipher_t* cipher, const char* text);
char* cipher_decrypt(cipher_t* cipher, const char* text);
/* Cleanup */
void cipher_destroy(cipher_t* cipher);
void cipher_free (char* str);

#endif //ENCRYPTION_CIPHER_API_H
