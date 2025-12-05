#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream sourceFile("source.txt");
    std::ofstream copyFile("copy.txt");
    
    if (sourceFile.fail()) {
        std::cout << "Ошибка: не удалось открыть файл source.txt" <<std::endl;
        return 1;
    }
    
    if (copyFile.fail()) {
        std::cout << "Ошибка: не удалось создать файл copy.txt" <<std::endl;
        sourceFile.close();
        return 1;
    }
    
    std::string line;
    int count = 0;
    
    while (std::getline(sourceFile, line)) {
        copyFile << line << "\n";
        count++;
    }
    
    sourceFile.close();
    copyFile.close();
    
    std::cout << "Файл успешно скопирован." << std::endl;
    std::cout << "Количество скопированных строк: " <<count<<std::endl;
    
    return 0;
}