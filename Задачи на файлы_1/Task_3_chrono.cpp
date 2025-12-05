#include <iostream>
#include <chrono>

int main() {
    long long total_seconds;
    
    std::cout << "Введите количество секунд: ";
    std::cin >> total_seconds;
    
    std::chrono::seconds input_seconds(total_seconds);
    
    auto hours = std::chrono::duration_cast<std::chrono::hours>(input_seconds);
    
    auto remaining_seconds = input_seconds - hours;
    
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(remaining_seconds);
    
    auto seconds = remaining_seconds - minutes;
    
    int h = hours.count();
    int m = minutes.count();
    int s = seconds.count();
    
    std::cout << h << " часов " << m << " минут " << s << " секунд" << std::endl;
    
    return 0;
}