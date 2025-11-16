#include <iostream>
#include <memory>

int main() {
    int size = 5;
    
    auto temp = std::make_unique<double[]>(size);
    auto pressure = std::make_unique<double[]>(size);
    auto humidity = std::make_unique<double[]>(size);
    
    temp[0] = 20.5; temp[1] = 22.1; temp[2] = 19.8; temp[3] = 21.3; temp[4] = 23.0;
    pressure[0] = 1013.2; pressure[1] = 1012.8; pressure[2] = 1014.1; pressure[3] = 1013.5; pressure[4] = 1012.9;
    humidity[0] = 65.0; humidity[1] = 62.5; humidity[2] = 68.3; humidity[3] = 63.7; humidity[4] = 61.2;
    
    double tempSum = 0, pressureSum = 0, humiditySum = 0;
    
    for (int i = 0; i < size; ++i) {
        tempSum += temp[i];
        pressureSum += pressure[i];
        humiditySum += humidity[i];
    }
    
    std::cout<<"Параметр\tСреднее значение"<<std::endl;
    std::cout<<"Температура\t"<<tempSum / size<<std::endl;
    std::cout<<"Давление\t"<<pressureSum / size<<std::endl;
    std::cout<<"Влажность\t"<<humiditySum / size<<std::endl;
    
    return 0;
}