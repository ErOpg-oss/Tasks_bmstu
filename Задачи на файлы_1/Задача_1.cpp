#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    
    if (file.fail()) {
        std::cout << "Ошибка: не удалось открыть файл input.txt"<<std::endl;
        return 1; 
    }
    
    std::cout << "Содержимое файла:" << std::endl;
    
    std::string line;
    while (std::getline(file, line)) {
        std::cout <<line<<std::endl;
    }
    
    file.close();
    
    return 0;
}