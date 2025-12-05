#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

int main() {
    std::ifstream inputFile("temperature_data.txt");
    
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл temperature_data.txt" << std::endl;
        return 1;
    }
    

    std::map<std::string, std::vector<double>> sensorData;
    
    std::string line;
    

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string sensorName;
        double temperature;
        
 
        if (ss >> sensorName >> temperature) {
            sensorData[sensorName].push_back(temperature);
        } else {
            std::cerr << "Ошибка чтения строки: " << line << std::endl;
        }
    }
    
    inputFile.close();
    
    std::ofstream outputFile("report.txt");
    
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка: не удалось создать файл report.txt" << std::endl;
        return 1;
    }
    
    for (const auto& pair : sensorData) {
        const std::string& sensorName = pair.first;
        const std::vector<double>& temperatures = pair.second;
        
        if (temperatures.empty()) {
            continue; 
        }
        
        double minTemp = *std::min_element(temperatures.begin(), temperatures.end());
        double maxTemp = *std::max_element(temperatures.begin(), temperatures.end());
        
        double sum = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
        double avgTemp = sum / temperatures.size();
        
        outputFile << std::fixed << std::setprecision(1);
        outputFile << sensorName << ": min = " << minTemp
                  << ", max = " << maxTemp
                  << ", avg = " << avgTemp << std::endl;
    }
    
    outputFile.close();
    
    std::cout << "Отчёт о температурных данных сохранён в report.txt" << std::endl;
    
    return 0;
}