//
// Created by ліна on 16.06.2026.
//

#include "VigenereCipher.h"
#include <string>

VigenereCipher::VigenereCipher(const std::string &key) {
    int length = key.size();
    for (int i = 0; i < length; i++) {
        char current_char = key[i];
        if (isalpha(current_char)) {
            key_ += tolower(current_char);
        }
    }
    if (key_.empty()) {
        throw std::invalid_argument("Vigenère key must contain at least one letter");
    }
}

std::string VigenereCipher::encrypt(const std::string &text) {
    int key_length = key_.size();
    int alpha_counter = 0;
    std::string new_string = "";
    for (char current_char : text) {
        if (isalpha(current_char)) {
            int current_key = key_[alpha_counter % key_length] - 'a';
            if (isupper(current_char)) {
                new_string += (current_char - 'A' + current_key) % 26 + 'A';
            }
            else {
                new_string += (current_char - 'a' + current_key) % 26 + 'a';
            }
            alpha_counter++;
        }
        else {
            new_string += current_char;
        }
    }
    return new_string;
}

std::string VigenereCipher::decrypt(const std::string &text) {
    int key_length = key_.size();
    int alpha_counter = 0;
    std::string new_string = "";
    for (char current_char : text) {
        if (isalpha(current_char)) {
            int current_key = key_[alpha_counter % key_length] - 'a';
            int rev_shift = (26 - current_key) % 26;
            if (isupper(current_char)) {
                new_string += (current_char - 'A' + rev_shift) % 26 + 'A';
            }
            else {
                new_string += (current_char - 'a' + rev_shift) % 26 + 'a';
            }
            alpha_counter++;
        }
        else {
            new_string += current_char;
        }
    }
    return new_string;
}

