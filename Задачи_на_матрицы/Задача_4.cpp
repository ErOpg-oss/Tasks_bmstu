#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int matrix[n][n];
    
    int value = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    
    while (value <= n * n) {
        for (int j = left; j <= right && value <= n * n; j++) {
            matrix[top][j] = value++;
        }
        top++;
        
        for (int i = top; i <= bottom && value <= n * n; i++) {
            matrix[i][right] = value++;
        }
        right--;
        
        for (int j = right; j >= left && value <= n * n; j--) {
            matrix[bottom][j] = value++;
        }
        bottom--;
        

        for (int i = bottom; i >= top && value <= n * n; i--) {
            matrix[i][left] = value++;
        }
        left++;
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}