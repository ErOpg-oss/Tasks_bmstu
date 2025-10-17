#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<double> power = {15.5, -2.3, 45.0, 78.2, 92.5, 12.1, 65.8, -1.0, 
                                33.3, 87.9, 5.5, 99.0, 22.7, 71.4, 18.9, 83.6, 
                                -0.5, 55.1, 29.8, 76.3};
    
    std::cout<<"Исходные измерения: ";
    for (double p : power) {
        std::cout<<p<<" ";
    }
    std::cout<<std::endl;
    
    power.erase(std::remove_if(power.begin(), power.end(), [](double p){ return p < 0; }), power.end());
    
    std::cout<<"Удаление ошибок: ";
    for (double p : power) {std::cout<<p<<" ";}
    std::cout<<std::endl;
    
    auto max_it = std::max_element(power.begin(), power.end());
    auto min_it = std::min_element(power.begin(), power.end());
    double average = std::accumulate(power.begin(), power.end(), 0.0) / power.size();
    
    std::cout<<"Минимальная мощность: "<<*min_it<<" кВт\n";
    std::cout<<"Максимальная мощность: "<<*max_it<<" кВт\n";
    std::cout<<"Средняя мощность: "<<average<<" кВт\n\n";
    
    bool in_range = true;
    for (double p : power) {
        if (p < 10 || p > 90) {
            in_range = false;
            break;
        }
    }
    
    if (in_range == true) {std::cout<<"Двигатель всегда в пределах 10-90"<<std::endl;} 
    else {std::cout<<"Двигатель не всегда в пределах 10-90"<<std::endl;}
    
    std::sort(power.begin(), power.end());
    
    std::cout<<"Отсортированные значения: ";
    for (double p : power) {std::cout<<p<<" ";}
    std::cout<<std::endl;
    
    double median;
    size_t size = power.size();
    if (size % 2 == 0) {
        median = (power[size/2 - 1] + power[size/2]) / 2.0;
    } else {
        median = power[size/2];
    }
    std::cout<<"Медиана: "<<median<<std::endl;
    
    return 0;
}