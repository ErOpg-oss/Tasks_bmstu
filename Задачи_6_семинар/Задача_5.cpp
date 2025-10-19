#include <iostream>
#include <cstring>
#include <cctype>

int main() {
    char str[200];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 200);

    int len = strlen(str);
    char word[100] = "";

    for (int i = 0; i <= len; ++i) {
        if (isalnum(str[i])) {
            int wLen = strlen(word);
            word[wLen] = str[i];
            word[wLen + 1] = '\0';
        } else {
            if (strlen(word) > 0) {
std::cout << word << std::endl;
                word[0] = '\0';
            }
        }
    }

    return 0;
}
