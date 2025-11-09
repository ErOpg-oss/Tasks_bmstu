#include <iostream>

int** transpose(int **matrix, int n, int m) {
    int **result = new int*[m];
    for (int i = 0; i < m; i++) {
        result[i] = new int[n];
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

int main() {
    int n = 2, m = 3;
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
            matrix[i][j] = i * m + j + 1;
        }
    }
    
    std::cout << "Исходная матрица:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    int **transposed = transpose(matrix, n, m);
    
    std::cout << "Транспонированная матрица:" << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << transposed[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i < n; i++) delete[] matrix[i];
    delete[] matrix;
    for (int i = 0; i < m; i++) delete[] transposed[i];
    delete[] transposed;
    
    return 0;
}
