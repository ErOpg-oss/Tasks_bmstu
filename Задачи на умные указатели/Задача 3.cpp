#include <iostream>
#include <memory>


void fillArray(std::unique_ptr<int[]>& arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = i * i;
    }
}

int main() {
    int N;
    
    std::cout<<"Введите размер массива N: ";
    std::cin >> N;

    std::unique_ptr<int[]> arr = std::make_unique<int[]>(N);
    
    fillArray(arr, N);
    
    std::cout<<"Массив квадратов: ";
    for (int i = 0; i < N; ++i) {
        std::cout<<arr[i];
        if (i < N - 1) std::cout<<", ";
    }
    std::cout<<std::endl;
    
    return 0;
}