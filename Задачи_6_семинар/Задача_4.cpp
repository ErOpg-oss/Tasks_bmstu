#include <iostream>
#include <cstring>
#include <cctype>

void countChars(const char* str, int counts[256]) {
    for (int i = 0; i < strlen(str); ++i) {
        counts[tolower(str[i])]++;
    }
}

int main() {
    char str1[100], str2[100];
    std::cout << "Введите первую строку: ";
    std::cin.getline(str1, 100);
    std::cout << "Введите вторую строку: ";
    std::cin.getline(str2, 100);

    int counts1[256] = {0};
    int counts2[256] = {0};

    countChars(str1, counts1);
    countChars(str2, counts2);

    bool isAnagram = true;
    for (int i = 0; i < 256; ++i) {
        if (counts1[i] != counts2[i]) {
            isAnagram = false;
            break;
        }
    }

    if (isAnagram) {
        std::cout << "Да" << std::endl;
    } else {
        std::cout << "Нет" << std::endl;
    }

    return 0;
}
