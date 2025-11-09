#!/bin/bash

# Задача 1
cat > "Задача 1.cpp" << 'EOF'
#include <iostream>

void swapPointers(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;
    
    std::cout << "Before swap:" << std::endl;
    std::cout << "p1 points to: " << *p1 << " at address: " << p1 << std::endl;
    std::cout << "p2 points to: " << *p2 << " at address: " << p2 << std::endl;
    
    swapPointers(&p1, &p2);
    
    std::cout << "After swap:" << std::endl;
    std::cout << "p1 points to: " << *p1 << " at address: " << p1 << std::endl;
    std::cout << "p2 points to: " << *p2 << " at address: " << p2 << std::endl;
    
    return 0;
}
EOF

# Задача 2
cat > "Задача 2.cpp" << 'EOF'
#include <iostream>

int main() {
    int n, m;
    std::cout << "Введите n и m: ";
    std::cin >> n >> m;
    
    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 100;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}
EOF

# Задача 3
cat > "Задача 3.cpp" << 'EOF'
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
EOF

# Задача 4
cat > "Задача 4.cpp" << 'EOF'
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
EOF

# Задача 5
cat > "Задача 5.cpp" << 'EOF'
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
EOF

# Задача 6
cat > "Задача 6.cpp" << 'EOF'
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
EOF

# Задача 7
cat > "Задача 7.cpp" << 'EOF'
#include <iostream>
#include <cstring>

void sortWords(char **words, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char *temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int count = 7;
    char *words[count] = {
        "banana", "apple", "cherry", "date", "elderberry", "fig", "grape"
    };
    
    std::cout << "До сортировки:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << words[i] << std::endl;
    }
    
    sortWords(words, count);
    
    std::cout << "После сортировки:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << words[i] << std::endl;
    }
    
    return 0;
}
EOF

# Задача 8
cat > "Задача 8.cpp" << 'EOF'
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
EOF

# Задача 9
cat > "Задача 9.cpp" << 'EOF'
#include <iostream>
#include <cstdlib>
#include <ctime>

double **allocateWeights(int n, int m) {
    double **weights = new double*[n];
    for (int i = 0; i < n; i++) {
        weights[i] = new double[m];
        for (int j = 0; j < m; j++) {
            weights[i][j] = (rand() % 110 - 10) / 10.0;
        }
    }
    return weights;
}

void freeWeights(double **weights, int n) {
    for (int i = 0; i < n; i++) {
        delete[] weights[i];
    }
    delete[] weights;
}

void normalizeWeights(double **weights, int n, int m) {
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < m; j++) {
            sum += weights[i][j];
        }
        if (sum > 1.0) {
            for (int j = 0; j < m; j++) {
                weights[i][j] /= sum;
            }
        }
    }
}

double *forward(double **weights, double *inputs, int n, int m) {
    double *outputs = new double[n];
    for (int i = 0; i < n; i++) {
        outputs[i] = 0.0;
        for (int j = 0; j < m; j++) {
            outputs[i] += weights[i][j] * inputs[j];
        }
    }
    return outputs;
}

int main() {
    srand(time(0));
    int n = 3, m = 4;
    
    double **weights = allocateWeights(n, m);
    double *inputs = new double[m];
    
    for (int i = 0; i < m; i++) {
        inputs[i] = (rand() % 100) / 100.0;
    }
    
    std::cout << "Матрица весов:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << weights[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Входные сигналы:" << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout << inputs[i] << " ";
    }
    std::cout << std::endl;
    
    double *outputs = forward(weights, inputs, n, m);
    
    std::cout << "Выходы нейронов:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << outputs[i] << " ";
    }
    std::cout << std::endl;
    
    normalizeWeights(weights, n, m);
    std::cout << "После нормализации:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << weights[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    freeWeights(weights, n);
    delete[] inputs;
    delete[] outputs;
    
    return 0;
}
EOF

# Задача 10
cat > "Задача 10.cpp" << 'EOF'
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
EOF

echo "Все файлы второй части созданы!"