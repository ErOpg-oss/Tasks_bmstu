#include <iostream>
#include <cstring>

int main() {
    char str[100];
    int shift;
    
    std::cout << "Текст: ";
    std::cin.getline(str, 100);
    std::cout << "Сдвиг: ";
    std::cin >> shift;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            str[i] = (str[i] - 'A' + shift) % 26 + 'A';
        } 
        else if (str[i] >= 'a' && str[i] <= 'z') 
        {
            str[i] = (str[i] - 'a' + shift) % 26 + 'a';
        }
    }
    
    std::cout << "Результат: " << str << std::endl;
    return 0;
}
