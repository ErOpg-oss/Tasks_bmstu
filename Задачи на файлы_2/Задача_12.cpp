#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

int main() {
    // Создание вектора с данными
    std::vector<int> numbers(100000);
    for (int i = 0; i < 100000; i++) {
        numbers[i] = i + 1;
    }
    
    // Лямбда для измерения времени
    auto measure_time = [](auto function) {
        auto start = std::chrono::steady_clock::now();
        function();
        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration<double>(end - start).count();
    };
    
    // Метод 1: запись каждого числа по отдельности
    double time1 = measure_time([&]() {
        std::ofstream f("method1.bin", std::ios::binary);
        for (int num : numbers) {
            f.write(reinterpret_cast<const char*>(&num), sizeof(int));
        }
        f.close();
    });
    
    // Метод 2: запись всех чисел сразу
    double time2 = measure_time([&]() {
        std::ofstream f("method2.bin", std::ios::binary);
        f.write(reinterpret_cast<const char*>(numbers.data()), 
                numbers.size() * sizeof(int));
        f.close();
    });
    
    // Вывод результатов
    std::cout << "=== Сравнение скорости записи ===\n";
    std::cout << "Метод 1 (по одному): " << time1 << " секунд\n";
    std::cout << "Метод 2 (все сразу): " << time2 << " секунд\n";
    std::cout << "Разница: " << (time1 - time2) << " секунд\n";
    std::cout << "Ускорение: " << (time1 / time2) << " раз\n";
    
    // Проверка размеров файлов
    std::ifstream f1("method1.bin", std::ios::binary | std::ios::ate);
    std::ifstream f2("method2.bin", std::ios::binary | std::ios::ate);
    
    std::cout << "Размер method1.bin: " << f1.tellg() << " байт\n";
    std::cout << "Размер method2.bin: " << f2.tellg() << " байт\n";
    
    f1.close();
    f2.close();
    
    return 0;
}
