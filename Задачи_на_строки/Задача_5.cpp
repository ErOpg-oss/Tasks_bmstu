#include <iostream>
#include <cstring>
#include <cctype>

int main() {
    char str[100];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 100);
    
    int vowels = 0;
    int consonants = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        char c = std::tolower(str[i]);
        
        if (c == 'a' ||  c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') 
        {
            vowels++;
        } 
        else if (c >= 'a' && c <= 'z') 
        {
            consonants++;
        }
    }
    
    std::cout << "Гласных: " << vowels << std::endl;
    std::cout << "Согласных: " << consonants << std::endl;
    
    return 0;
}