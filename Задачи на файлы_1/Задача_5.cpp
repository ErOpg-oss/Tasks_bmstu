#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл text.txt" <<std::endl;
        return 1;
    }
    
    int count = 0;
    char ch;
    
    while (file.get(ch)) {
        count++;
    }
    
    std::cout << "Количество символов в файле: " <<count<<std::endl;
    
    file.close();
    
    return 0;
}