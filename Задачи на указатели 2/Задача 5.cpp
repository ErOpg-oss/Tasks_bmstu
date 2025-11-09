#include <iostream>

int sumRow(int *row, int m) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += row[i];
    }
    return sum;
}

void sortRowsBySum(int **arr, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sumRow(arr[j], m) > sumRow(arr[j + 1], m)) {
                int *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 4, m = 3;
    int **arr = new int*[n];
    int values[4][3] = {{1, 2, 3}, {9, 8, 7}, {4, 5, 6}, {0, 1, 0}};
    
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            arr[i][j] = values[i][j];
        }
    }
    
    std::cout << "До сортировки:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << " (sum: " << sumRow(arr[i], m) << ")" << std::endl;
    }
    
    sortRowsBySum(arr, n, m);
    
    std::cout << "После сортировки:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << " (sum: " << sumRow(arr[i], m) << ")" << std::endl;
    }
    
    for (int i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;
    
    return 0;
}
