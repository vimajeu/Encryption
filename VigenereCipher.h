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
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
};


#endif //ENCRYPTION_VIGENERECIPHER_H
