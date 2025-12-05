#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file1("file1.txt");
    std::ifstream file2("file2.txt");  

    if (file1.fail() || file2.fail()) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    std::string line1, line2;

    while (std::getline(file1, line1)) {
        if (!std::getline(file2, line2)) {
            std::cout << "Файлы различаются" << std::endl;
            return 0;
        }
        if (line1 != line2) {
            std::cout << "Файлы различаются" << std::endl;
            return 0;
        }
    }

    if (std::getline(file2, line2)) {
        std::cout << "Файлы различаются" << std::endl;
        return 0;
    }

    std::cout << "Файлы идентичны" << std::endl;
    
    return 0;
}