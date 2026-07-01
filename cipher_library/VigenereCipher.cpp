//
// Created by ліна on 16.06.2026.
//

#include "VigenereCipher.h"
#include <string>
#include <stdexcept>

VigenereCipher::VigenereCipher(const std::string &key) {
    if (key.empty()) {
        throw std::invalid_argument("Vigenère key must not be empty");
    }
    key_ = key;
}

std::vector<uint8_t> VigenereCipher::encrypt(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result;
    for (size_t i = 0; i < data.size(); i++) {
        uint8_t keyByte = static_cast<uint8_t>(key_[i % key_.size()]);
        result.push_back(static_cast<uint8_t>((data[i] + keyByte) % 256));
    }
    return result;
}

std::vector<uint8_t> VigenereCipher::decrypt(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> result;
    for (size_t i = 0; i < data.size(); i++) {
        uint8_t keyByte = static_cast<uint8_t>(key_[i % key_.size()]);
        result.push_back(static_cast<uint8_t>((data[i] - keyByte + 256) % 256));
    }
    return result;
}

