#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    int matrix[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            std::cout << matrix[top][j] << " ";
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            std::cout << matrix[i][right] << " ";
        }
        right--;
        
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                std::cout << matrix[bottom][j] << " ";
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                std::cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    
    return 0;
}