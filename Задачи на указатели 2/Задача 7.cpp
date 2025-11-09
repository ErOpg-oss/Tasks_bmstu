#include <iostream>
#include <cstring>

void sortWords(char **words, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char *temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int count = 7;
    char *words[count] = {
        "banana", "apple", "cherry", "date", "elderberry", "fig", "grape"
    };
    
    std::cout << "До сортировки:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << words[i] << std::endl;
    }
    
    sortWords(words, count);
    
    std::cout << "После сортировки:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << words[i] << std::endl;
    }
    
    return 0;
}
