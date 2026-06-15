//
// Created by ліна on 16.06.2026.
//

#ifndef ENCRYPTION_CIPHER_H
#define ENCRYPTION_CIPHER_H

#include <string>


class Cipher {
public:
    virtual std::string encrypt(const std::string& text) = 0;
    virtual std::string decrypt(const std::string& text) = 0;

    virtual ~Cipher() = default;
};


#endif //ENCRYPTION_CIPHER_H
