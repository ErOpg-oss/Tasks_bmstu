#include <iostream>

double *averageLoadPerNode(int **load, int n, int t) {
    double *averages = new double[n];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < t; j++) {
            sum += *(*(load + i) + j);
        }
        averages[i] = static_cast<double>(sum) / t;
    }
    return averages;
}

void normalizeLoad(int **load, int n, int t) {
    double *averages = averageLoadPerNode(load, n, t);
    
    for (int j = 0; j < t; j++) {
        for (int i = 0; i < n; i++) {
            if (averages[i] > 80.0) {
                int overload = *(*(load + i) + j) - 80;
                if (overload > 0) {
                    int transfer = overload / (n - 1);
                    *(*(load + i) + j) = 80;
                    
                    for (int k = 0; k < n; k++) {
                        if (k != i) {
                            *(*(load + k) + j) += transfer;
                            if (*(*(load + k) + j) > 100) {
                                *(*(load + k) + j) = 100;
                            }
                        }
                    }
                }
            }
        }
    }
    
    delete[] averages;
}

int findCriticalInterval(int **load, int n, int t) {
    int maxSum = 0, criticalInterval = 0;
    
    for (int j = 0; j < t; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += *(*(load + i) + j);
        }
        if (sum > maxSum) {
            maxSum = sum;
            criticalInterval = j;
        }
    }
    return criticalInterval;
}

void printMatrix(int **load, int n, int t) {
    std::cout << "Матрица нагрузок:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Узел " << i << ": ";
        for (int j = 0; j < t; j++) {
            std::cout << *(*(load + i) + j) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, t;
    std::cout << "Введите количество узлов и интервалов: ";
    std::cin >> n >> t;
    
    int **load = new int*[n];
    for (int i = 0; i < n; i++) {
        load[i] = new int[t];
        std::cout << "Узел " << i << ": ";
        for (int j = 0; j < t; j++) {
            std::cin >> load[i][j];
        }
    }
    
    std::cout << "\n=== Анализ нагрузки ===" << std::endl;
    printMatrix(load, n, t);
    
    double *averages = averageLoadPerNode(load, n, t);
    std::cout << "\nСредняя нагрузка по узлам:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Узел " << i << ": " << averages[i] << "%" << std::endl;
    }
    
    normalizeLoad(load, n, t);
    std::cout << "\nПосле нормализации:" << std::endl;
    printMatrix(load, n, t);
    
    int critical = findCriticalInterval(load, n, t);
    std::cout << "\nКритический интервал: " << critical << std::endl;
    
    delete[] averages;
    for (int i = 0; i < n; i++) {
        delete[] load[i];
    }
    delete[] load;
    
    return 0;
}
