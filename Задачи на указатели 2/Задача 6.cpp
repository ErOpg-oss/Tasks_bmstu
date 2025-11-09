#include <iostream>

int sumElements(int **arr, int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += *(*(arr + i) + j);
        }
    }
    return sum;
}

int main() {
    int n = 3, m = 5;
    int **arr = new int*[n];
    int counter = 1;
    
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            arr[i][j] = counter++;
        }
    }
    
    std::cout << "Массив:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Сумма элементов: " << sumElements(arr, n, m) << std::endl;
    
    for (int i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;
    
    return 0;
}
