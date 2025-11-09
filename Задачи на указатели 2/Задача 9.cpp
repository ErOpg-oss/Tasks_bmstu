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
