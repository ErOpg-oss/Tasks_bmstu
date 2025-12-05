#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt");
    
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл numbers.txt" <<std::endl;
        return 1;
    }
    
    int count = 0;
    double sum = 0;
    int number;
    
    while (file >> number) {
        count++;
        sum += number;
    }
    
    file.close();
    
    std::cout << "Количество чисел: " << count <<std::endl;
    std::cout << "Сумма: " << sum <<std::endl;
    
    if (count > 0) {
        std::cout << "Среднее: " << sum / count <<std::endl;
    } else {
        std::cout << "файл пуст" <<std::endl;
    }
    
    return 0;
}