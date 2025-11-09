#include <iostream>

void free2D(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int n = 3, m = 4;
    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            arr[i][j] = i * m + j;
        }
    }
    
    std::cout << "Массив создан" << std::endl;
    free2D(arr, n);
    std::cout << "Память освобождена" << std::endl;
    
    return 0;
}
