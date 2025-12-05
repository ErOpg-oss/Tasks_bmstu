#include <iostream>
#include <chrono>

long long calculate(long long N) {
    long long sum = 0;
    for (long long i = 1; i <= N; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    long long N;
    
    std::cout << "Введите число N: \n";
    std::cin >> N;
    
    std::cout << "Вычисляем сумму чисел от 1 до " << N << "..." << std::endl;
    
    auto start_time = std::chrono::high_resolution_clock::now();
    
    long long result = calculate(N);
    
    auto end_time = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    
    std::cout << "Сумма чисел от 1 до " << N << " = " << result << std::endl;
    std::cout << "Время выполнения: " << duration.count() << " миллисекунд" << std::endl;
    
    return 0;
}