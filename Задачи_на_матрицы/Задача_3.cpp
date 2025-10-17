#include <iostream>
#include <climits>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    int matrix[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    int row_min[n], row_max[n];
    int col_min[m], col_max[m];
    
    for (int i = 0; i < n; i++) {
        row_min[i] = INT_MAX;
        row_max[i] = INT_MIN;
    }
    for (int j = 0; j < m; j++) {
        col_min[j] = INT_MAX;
        col_max[j] = INT_MIN;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int current = matrix[i][j];
            
            if (current < row_min[i]) row_min[i] = current;
            if (current > row_max[i]) row_max[i] = current;
            
            if (current < col_min[j]) col_min[j] = current;
            if (current > col_max[j]) col_max[j] = current;
        }
    }
    
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int current = matrix[i][j];
            
        
            if (current == row_min[i] && current == col_max[j]) {
                std::cout << "A " << current << " " << i+1 << " " << j+1 << std::endl;
                found = true;
            }
         
            if (current == row_max[i] && current == col_min[j]) {
                std::cout << "B " << current << " " << i+1 << " " << j+1 << std::endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        std::cout << "NONE" << std::endl;
    }
    
    return 0;
}