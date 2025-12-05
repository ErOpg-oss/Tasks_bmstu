#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("text.txt");
    
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл text.txt" <<std::endl;
        return 1;
    }
    
    int count = 0;
    std::string word;
    
    while (file >> word) {
        count++;
    }
    
    std::cout << "Количество слов в файле: " <<count<<std::endl;
    
    file.close();
    
    return 0;
}