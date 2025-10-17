#include <iostream>
#include <cstring>

int main() {
    char str[100];
    std::cout << "Введите текст: ";
    std::cin.getline(str, 100);
    
    bool newSentence = true;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (newSentence && ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 'a' + 'A';
            }
            newSentence = false;
        } 
        else if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] - 'A' + 'a';
            }
        }
        
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
            newSentence = true;
        }
    }
    
    std::cout << "Результат: " << str << std::endl;
    
    return 0;
}