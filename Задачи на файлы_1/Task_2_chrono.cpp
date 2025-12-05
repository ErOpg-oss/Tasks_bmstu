#include <chrono>
#include <iostream>
#include <thread>

int main() {
    int n = 0;
    std::cout << "Введите количество секунд: ";
    std::cin >> n;
    
    std::cout << "Таймер запущен:\n" << std::endl;
    
    while (n > 0) {
        std::cout << "Осталось: " << n << " секунд" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        n--;
    }
    
    std::cout << "Время вышло!" << std::endl;
    
    return 0;
}