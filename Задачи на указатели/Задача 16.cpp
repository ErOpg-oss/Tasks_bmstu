#include <iostream>
#include <vector>

void analyzePressure(const std::vector<double>& data, double& minVal, double& maxVal, double& avgVal) {
    const double* p = data.data();
    size_t n = data.size();
    
    minVal = *p;
    maxVal = *p;
    double sum = 0.0;
    
    for (size_t i = 0; i < n; i++) {
        double current = *(p + i);
        if (current < minVal) minVal = current;
        if (current > maxVal) maxVal = current;
        sum += current;
    }
    
    avgVal = sum / n;
}

int main() {
    std::vector<double> pressure = {101.3, 100.8, 101.9, 100.5, 102.0};
    double minVal, maxVal, avgVal;
    
    analyzePressure(pressure, minVal, maxVal, avgVal);
    
    std::cout << "Min pressure: " << minVal << std::endl;
    std::cout << "Max pressure: " << maxVal << std::endl;
    std::cout << "Average pressure: " << avgVal << std::endl;
    
    return 0;
}
