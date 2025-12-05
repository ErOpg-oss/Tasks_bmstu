#include <iostream>
#include <fstream>
#include <string>

int main() {
    int count = 0;
    std::ifstream file("data.txt");
    
    if (file.fail()) {
        std::cout << "Ошибка: не удалось открыть файл input.txt" << std::endl;
        return 1; 
    }
    
    std::string line;
    while (std::getline(file, line)) {
        count++;
    }

    std::cout<<"Количество строк в файле: "<<count<<std::endl;
    
    file.close();
    
    return 0;
}