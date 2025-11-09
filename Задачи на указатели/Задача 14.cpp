#include <iostream>
#include <vector>
#include <cmath>

double computeRMS(const std::vector<double>& signal) {
    const double* p = signal.data();
    double sum = 0.0;
    size_t n = signal.size();
    
    for (size_t i = 0; i < n; i++) {
        sum += (*(p + i)) * (*(p + i));
    }
    
    return sqrt(sum / n);
}

int main() {
    std::vector<double> signal = {2.0, 3.0, 1.0, 4.0, 3.0};
    std::cout << "RMS value: " << computeRMS(signal) << std::endl;
    return 0;
}
