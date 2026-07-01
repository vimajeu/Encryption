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
    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& data) override;
    std::vector<uint8_t> decrypt(const std::vector<uint8_t>& data) override;
};


#endif //ENCRYPTION_CAESARCIPHER_H
