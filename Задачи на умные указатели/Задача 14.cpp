#include <iostream>
#include <memory>
#include <vector>

int main() {
    int N, M;
    std::cout<<"Введите N: ";
    std::cin >> N;
    std::cout<<"Введите M: ";
    std::cin >> M;

    auto matrix = std::make_unique<double[]>(N * M);

    std::cout<<"Введите элементы матрицы:"<<std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> matrix[i * M + j];
        }
    }

    auto sumColumns = [&]() {
        std::vector<double> sums(M, 0.0);
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                sums[j] += matrix[i * M + j];
            }
        }
        return sums;
    };

    auto maxIndex = [](const std::vector<double>& sums) {
        int maxIdx = 0;
        for (int i = 1; i < sums.size(); ++i) {
            if (sums[i] > sums[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    };

    std::vector<double> sums = sumColumns();
    int maxCol = maxIndex(sums);

    std::cout<<"Суммы столбцов: [";
    for (int i = 0; i < M; ++i) {
        std::cout<<sums[i];
        if (i < M - 1) std::cout<<", ";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Столбец с максимальной суммой: "<<maxCol + 1<<" ("<<sums[maxCol]<<")"<<std::endl;

    return 0;
}