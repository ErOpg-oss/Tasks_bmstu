#include <iostream>
#include <memory>

int main() {
    int N, M;
    
    std::cout<<"Введите количество строк N: ";
    std::cin >> N;
    std::cout<<"Введите количество столбцов M: ";
    std::cin >> M;
    
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(N * M);
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            arr[i * M + j] = i * j;
        }
    }
    
    std::cout<<"Таблица произведений:"<<std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout<<arr[i * M + j]<<"\t";
        }
        std::cout<<std::endl;
    }
    
    return 0;
}