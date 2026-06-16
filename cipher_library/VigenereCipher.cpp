//
// Created by ліна on 16.06.2026.
//

#include "../VigenereCipher.h"
#include <string>

VigenereCipher::VigenereCipher(const std::string &key) {
    int length = key.size();
    for (int i = 0; i < length; i++) {
        char current_char = key[i];
        if (isalpha(current_char)) {
            key_ += tolower(current_char);
        }
    }
}

std::string VigenereCipher::encrypt(const std::string &text) {
    int text_length = text.size();
    int key_length = key_.size();
    int symb_counter = 0;
    std::string new_string = "";
    for (int i = 0; i < text_length; i++) {
        char current_char = text[i];
        if (isalpha(current_char)) {
            int current_key = key_[(i - symb_counter) % key_length] - 'a';
            if (isupper(current_char)) {
                new_string += (current_char - 'A' + current_key) % 26 + 'A';
            }
            else {
                new_string += (current_char - 'a' + current_key) % 26 + 'a';
            }
        }
        else {
            new_string += current_char;
            symb_counter++;
        }
    }
    return new_string;
}

std::string VigenereCipher::decrypt(const std::string &text) {
    int text_length = text.size();
    int key_length = key_.size();
    int symb_counter = 0;
    std::string new_string = "";
    for (int i = 0; i < text_length; i++) {
        char current_char = text[i];
        if (isalpha(current_char)) {
            int current_key = key_[(i - symb_counter) % key_length] - 'a';
            if (isupper(current_char)) {
                new_string += (current_char - 'A' + (26 - current_key) % 26) % 26 + 'A';
            }
            else {
                new_string += (current_char - 'a' + (26 - current_key) % 26) % 26 + 'a';
            }
        }
        else {
            new_string += current_char;
            symb_counter++;
        }
    }
    return new_string;
}

