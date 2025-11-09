#include <iostream>
#include <iomanip>

double **allocatePlate(int n, int m) {
    double **plate = new double*[n];
    for (int i = 0; i < n; i++) {
        plate[i] = new double[m];
        for (int j = 0; j < m; j++) {
            plate[i][j] = 20.0;
        }
    }
    plate[n/2][m/2] = 100.0;
    return plate;
}

void freePlate(double **plate, int n) {
    for (int i = 0; i < n; i++) {
        delete[] plate[i];
    }
    delete[] plate;
}

void updateTemperature(double **plate, int n, int m) {
    double **newPlate = new double*[n];
    for (int i = 0; i < n; i++) {
        newPlate[i] = new double[m];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == n/2 && j == m/2) {
                newPlate[i][j] = 100.0;
                continue;
            }
            
            double sum = 0.0;
            int count = 0;
            
            if (i > 0) { sum += plate[i-1][j]; count++; }
            if (i < n-1) { sum += plate[i+1][j]; count++; }
            if (j > 0) { sum += plate[i][j-1]; count++; }
            if (j < m-1) { sum += plate[i][j+1]; count++; }
            
            newPlate[i][j] = sum / count;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            plate[i][j] = newPlate[i][j];
        }
        delete[] newPlate[i];
    }
    delete[] newPlate;
}

int main() {
    int n = 5, m = 5, iterations = 10;
    double **plate = allocatePlate(n, m);
    
    std::cout << "Начальное распределение температуры:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::fixed << std::setprecision(1) << plate[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    for (int k = 0; k < iterations; k++) {
        updateTemperature(plate, n, m);
    }
    
    std::cout << "После " << iterations << " итераций:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::fixed << std::setprecision(1) << plate[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    freePlate(plate, n);
    return 0;
}
