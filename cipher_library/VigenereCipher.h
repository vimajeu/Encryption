//
// Created by ліна on 16.06.2026.
//

#ifndef ENCRYPTION_VIGENERECIPHER_H
#define ENCRYPTION_VIGENERECIPHER_H
#include "Cipher.h"
#include <string>


class VigenereCipher : public Cipher {
    std::string key_;
public:
    VigenereCipher(const std::string& key);
    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& data) override;
    std::vector<uint8_t> decrypt(const std::vector<uint8_t>& data) override;
};


#endif //ENCRYPTION_VIGENERECIPHER_H
