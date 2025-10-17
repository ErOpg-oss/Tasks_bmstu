#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int M[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> M[i][j];
        }
    }

    int main_sum = 0;
    for (int j = 0; j < n; j++) {
        main_sum += M[0][j];
    }
    
    bool magic = true;
    
    // Проверка сумм строк
    for (int i = 1; i < n && magic; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += M[i][j];
        }
        if (row_sum != main_sum) {
            magic = false;
        }
    }
    
    for (int j = 0; j < n && magic; j++) {
        int col_sum = 0;
        for (int i = 0; i < n; i++) {
            col_sum += M[i][j];
        }
        if (col_sum != main_sum) {
            magic = false;
        }
    }
    
    if (magic) {
        int main_diag_sum = 0;
        for (int i = 0; i < n; i++) {
            main_diag_sum += M[i][i];
        }
        if (main_diag_sum != main_sum) {
            magic = false;
        }
    }

    if (magic) {
        int reverse_diag_sum = 0;
        for (int i = 0; i < n; i++) {
            reverse_diag_sum += M[i][n - 1 - i];
        }
        if (reverse_diag_sum != main_sum) {
            magic = false;
        }
    }
    
    if (magic) {
        std::cout<<"YES " << main_sum << std::endl;
    } else {
        std::cout<<"NO"<< std::endl;
    }
    
    return 0;
}