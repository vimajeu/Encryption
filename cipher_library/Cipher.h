//
// Created by ліна on 16.06.2026.
//

#ifndef ENCRYPTION_CIPHER_H
#define ENCRYPTION_CIPHER_H

#include <vector>


class Cipher {
public:
    virtual std::vector<uint8_t> encrypt(const std::vector<uint8_t>& data) = 0;
    virtual std::vector<uint8_t> decrypt(const std::vector<uint8_t>& data) = 0;

    virtual ~Cipher() = default;
};


#endif //ENCRYPTION_CIPHER_H
