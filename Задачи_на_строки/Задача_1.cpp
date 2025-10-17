#include <iostream>
#include <cstring>
#include <cctype>

bool isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        while (left < right && std::isspace(str[left])) left++;
        while (left < right && std::isspace(str[right])) right--;
        
        if (std::tolower(str[left]) != std::tolower(str[right])) return false;
        
        left++;
        right--;
    }
    return true;
}

int main() {
    char str[100];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 100);
    
    if (isPalindrome(str)) std::cout << "Палиндром" << std::endl;
    else std::cout << "Не палиндром" << std::endl;
    
    return 0;
}
