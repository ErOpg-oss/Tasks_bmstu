#include <iostream>
#include <cstring>
#include <cctype>

int main() {
    char str[100];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 100);
    
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!std::isdigit(str[i])) str[j++] = str[i];
    }
    str[j] = '\0';
    
    std::cout << "Результат: " << str << std::endl;
    return 0;
}
