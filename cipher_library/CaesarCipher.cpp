//
// Created by ліна on 16.06.2026.
//

#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(int key) {
    key_ = (key % 256 + 256) % 256;
}

std::vector<uint8_t> CaesarCipher::encrypt(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result;
    for (uint8_t byte : data) {
        result.push_back(static_cast<uint8_t>((byte + key_) % 256));
    }
    return result;
}

std::vector<uint8_t> CaesarCipher::decrypt(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result;
    for (uint8_t byte : data) {
        result.push_back(static_cast<uint8_t>((byte - key_ + 256) % 256));
    }
    return result;
}
