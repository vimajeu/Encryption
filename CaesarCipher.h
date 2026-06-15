//
// Created by ліна on 16.06.2026.
//

#ifndef ENCRYPTION_CAESARCIPHER_H
#define ENCRYPTION_CAESARCIPHER_H
#include "Cipher.h"
#include <string>


class CaesarCipher : public Cipher {
    int key_;
public:
    CaesarCipher(int key);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
};


#endif //ENCRYPTION_CAESARCIPHER_H
