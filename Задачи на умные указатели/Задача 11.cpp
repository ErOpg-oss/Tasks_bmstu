#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> signals = {25.4, 27.1, 30.0, 29.5, 28.3};
    int N = signals.size();
    
    auto signals_ptr = std::make_unique<double[]>(N);
    for (int i = 0; i < N; ++i) {
        signals_ptr[i] = signals[i];
    }
    
    auto mean = [](std::unique_ptr<double[]>& arr, int size) -> double {
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return sum / size;
    };
    
    auto normalize = [](std::unique_ptr<double[]>& arr, int size, double max_val) {
        for (int i = 0; i < size; ++i) {
            arr[i] /= max_val;
        }
    };
    
    auto copyBack = [&](std::unique_ptr<double[]>& arr, int size) {
        for (int i = 0; i < size; ++i) {
            signals[i] = arr[i];
        }
    };
    
    std::cout<<"Исходные данные: ";
    for (auto val : signals) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    
    double avg = mean(signals_ptr, N);
    std::cout<<"Среднее значение: "<<avg<<std::endl;
    
    double max_val = *std::max_element(signals.begin(), signals.end());
    normalize(signals_ptr, N, max_val);
    copyBack(signals_ptr, N);
    
    std::cout<<"Нормализованные сигналы: ";
    for (auto val : signals) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    
    return 0;
}