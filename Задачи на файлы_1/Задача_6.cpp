#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream file("output.txt");
    
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось создать файл output.txt" <<std::endl;
        return 1;
    }
    
    std::cout << "Введите строки (пустая строка завершает ввод):" <<std::endl;
    
    std::string line;
    int count = 0;
    
    std::getline(std::cin, line);
    
    while (!line.empty()) {
        file << line << std::endl;
        count++;
        
        std::getline(std::cin, line);
    }
    
    file.close();
    
    std::cout << "Данные записаны в файл output.txt." <<std::endl;
    std::cout << "Количество записанных строк: " <<count<<std::endl;
    
    return 0;
}