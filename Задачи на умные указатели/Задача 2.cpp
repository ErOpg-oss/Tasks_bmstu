#include <iostream>
#include <memory>

int main() {
    int N;
    
    std::cout<<"Введите размер массива N: ";
    std::cin >> N;
    
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(N);
    
    for (int i = 0; i < N; ++i) {
        arr[i] = i + 1;
    }
    
    std::cout<<"Содержимое массива: ";
    for (int i = 0; i < N; ++i) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    
    return 0;
}