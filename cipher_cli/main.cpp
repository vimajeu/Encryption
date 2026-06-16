//
// Created by ліна on 16.06.2026.
//

#include <iostream>
#include <string>
#include <dlfcn.h>

typedef void* cipher_t;
typedef cipher_t* (*create_caesar_funct)(int);
typedef cipher_t* (*create_vigenere_funct)(const char*);
typedef char* (*encrypt_funct)(cipher_t*, const char*);
typedef char* (*decrypt_funct)(cipher_t*, const char*);
typedef void (*destroy_funct)(cipher_t*);
typedef void (*free_funct)(char*);

int main() {
    void* handle = dlopen("libcipher.dylib", RTLD_LAZY);
    if (!handle) {
        std::cout << "Помилка: Не вдалося знайти або завантажити libcipher.dylib!\n";
        std::cout << "Деталі помилки Mac: " << dlerror() << "\n";
        return 1;
    }

    auto caesar = (create_caesar_funct)dlsym(handle, "cipher_create_caesar");
    auto vigenere = (create_vigenere_funct)dlsym(handle, "cipher_create_vigenere");
    auto encrypt = (encrypt_funct)dlsym(handle, "cipher_encrypt");
    auto decrypt = (decrypt_funct)dlsym(handle, "cipher_decrypt");
    auto destroy_cipher = (destroy_funct)dlsym(handle, "cipher_destroy");
    auto free_cipher = (free_funct)dlsym(handle, "cipher_free");

    int command;
    std::cout << "1. Create Caesar cipher\n";
    std::cout << "2. Create Vigenere cipher\n";
    std::cout << "Choose a command: \n";
    std::cin >> command;

    switch (command) {
        case 1: {
            int command_c;
            int key_c;
            std::string text_encr_c;
            std::string text_decr_c;

            std::cout << "Enter the key: \n";
            std::cin >> key_c;
            cipher_t *cipher_c = caesar(key_c);

            std::cout << "1. Encrypt\n";
            std::cout << "2. Decrypt\n";
            std::cout << "Choose a command: \n";
            std::cin >> command_c;
            switch (command_c) {
                case 1: {
                    std::cout << "Enter text: \n";
                    std::cin >> text_encr_c;
                    char* encr = encrypt(cipher_c, text_encr_c.c_str());
                    std::cout << encr;
                    free_cipher(encr);
                    break;
                }
                case 2: {
                    std::cout << "Enter text: \n";
                    std::cin >> text_decr_c;
                    char* decr = decrypt(cipher_c, text_decr_c.c_str());
                    std::cout << decr;
                    free_cipher(decr);
                    break;
                }
            }
            destroy_cipher(cipher_c);
            break;
        }
        case 2: {
            int command_v;
            std::string key_v;
            std::string text_encr_v;
            std::string text_decr_v;

            std::cout << "Enter the key: \n";
            std::cin >> key_v;
            cipher_t *cipher_v = vigenere(key_v.c_str());

            std::cout << "1. Encrypt\n";
            std::cout << "2. Decrypt\n";
            std::cout << "Choose a command: \n";
            std::cin >> command_v;
            switch (command_v) {
                case 1: {
                    std::cout << "Enter text: \n";
                    std::cin >> text_encr_v;
                    char* encr = encrypt(cipher_v, text_encr_v.c_str());
                    std::cout << encr;
                    free_cipher(encr);
                    break;
                }
                case 2: {
                    std::cout << "Enter text: \n";
                    std::cin >> text_decr_v;
                    char* decr = decrypt(cipher_v, text_decr_v.c_str());
                    std::cout << decr;
                    free_cipher(decr);
                    break;
                }
            }
            destroy_cipher(cipher_v);
            break;
        }
    }
}