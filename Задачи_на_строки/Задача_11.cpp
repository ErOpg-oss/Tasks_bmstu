#include <iostream>
#include <cstring>

bool hasUniqueChars(char str[], int start, int k) {
    for (int i = start; i < start + k; i++) {
        for (int j = i + 1; j < start + k; j++) {
            if (str[i] == str[j]) return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    int k;
    
    std::cout << "Строка: ";
    std::cin.getline(str, 100);
    std::cout << "k = ";
    std::cin >> k;
    
    int length = strlen(str);
    
    for (int i = 0; i <= length - k; i++) {
        if (hasUniqueChars(str, i, k)) {
            for (int j = i; j < i + k; j++) std::cout << str[j];
            std::cout << std::endl;
        }
    }
    
    return 0;
}
