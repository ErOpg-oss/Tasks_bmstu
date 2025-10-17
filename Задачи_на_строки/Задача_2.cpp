#include <iostream>
#include <cstring>

int main() {
    char str[100];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 100);
    
    int count = 0;
    char unique[100] = "";
    
    for (int i = 0; str[i] != '\0'; i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                found = true;
                break;
            }
        }
        if (!found) unique[count++] = str[i];
    }
    
    std::cout << "Уникальных символов: " << count << std::endl;
    std::cout << "Символы: ";
    for (int i = 0; i < count; i++) std::cout << unique[i] << " ";
    std::cout << std::endl;
    
    return 0;
}
