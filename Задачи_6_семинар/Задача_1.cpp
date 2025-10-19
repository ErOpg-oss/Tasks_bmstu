#include <iostream>
#include <cstring>

int main() {
    char str[200];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 200);

    char longestWord[100] = "";
    char word[100] = "";
    int maxLen = 0;
    int lenght = strlen(str);

    for (int i = 0; i <= lenght; ++i) {
        if ((tolower(str[i])) >= 'A' && (tolower(str[i]) <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
            
            int wordLen = strlen(word);
            word[wordLen] = str[i];
            word[wordLen + 1] = '\0';
        } 
        else {
            if (strlen(word) > maxLen) {
                maxLen = strlen(word);
                strcpy(longestWord, word);
            }
            word[0] = '\0'; 
        }
    }

    std::cout << "Самое длинное слово: " << longestWord << std::endl;

    return 0;
}