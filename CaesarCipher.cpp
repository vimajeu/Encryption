//
// Created by ліна on 16.06.2026.
//

#include "CaesarCipher.h"
#include <string>

CaesarCipher::CaesarCipher(int key) {
    key_ = (key % 26 + 26) % 26;
}

std::string CaesarCipher::encrypt(const std::string& text) {
    int length = text.size();
    std::string new_string = "";
    for (int i = 0; i < length; i++) {
        char current_char = text[i];
        if (isalpha(current_char)) {
            if (isupper(current_char)) {
                new_string += (current_char - 'A' + key_) % 26 + 'A';
            }
            else {
                new_string += (current_char - 'a' + key_) % 26 + 'a';
            }
        }
        else {
            new_string += current_char;
        }
    }
    return new_string;
}

std::string CaesarCipher::decrypt(const std::string &text) {
    int length = text.size();
    std::string new_string = "";
    for (int i = 0; i < length; i++) {
        char current_char = text[i];
        if (isalpha(current_char)) {
            if (isupper(current_char)) {
                new_string += (current_char - 'A' + (26 - key_) % 26) % 26 + 'A';
            }
            else {
                new_string += (current_char - 'a' + (26 - key_) % 26) % 26 + 'a';
            }
        }
        else {
            new_string += current_char;
        }
    }
    return new_string;
}
