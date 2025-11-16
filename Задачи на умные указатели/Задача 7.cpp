#include <iostream>
#include <memory>
#include <cstring>

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    const char* str = "Hello World";
    int len = strlen(str);
    
    std::unique_ptr<char[]> arr = std::make_unique<char[]>(len + 1);
    strcpy(arr.get(), str);
    
    int vowels = 0, consonants = 0;
    for (int i = 0; i < len; ++i) {
        if (isalpha(arr[i])) {
            if (isVowel(arr[i])) vowels++;
            else consonants++;
        }
    }
    
    std::cout<<"Строка: "<<arr.get()<<std::endl;
    std::cout<<"Гласные: "<<vowels<<", Согласные: "<<consonants<<std::endl;
    
    auto vowelsArr = std::make_unique<char[]>(vowels + 1);
    int idx = 0;
    for (int i = 0; i < len; ++i) {
        if (isVowel(arr[i])) {
            vowelsArr[idx++] = arr[i];
        }
    }
    vowelsArr[vowels] = '\0';
    
    std::cout<<"Только гласные: "<<vowelsArr.get()<<std::endl;
    
    return 0;
}