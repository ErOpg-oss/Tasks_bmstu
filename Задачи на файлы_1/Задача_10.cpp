#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <numeric>
#include <iomanip>

int main() {
    std::ifstream inputFile("power_log.txt");
    
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл power_log.txt" << std::endl;
        return 1;
    }
    
    std::map<std::string, std::vector<double>> deviceData;
    std::string line;
    
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string timestamp, deviceName;
        double power;
        
        if (ss >> timestamp >> deviceName >> power) {
            deviceData[deviceName].push_back(power);
        }
    }
    
    inputFile.close();
    
    if (deviceData.empty()) {
        std::cout << "Файл power_log.txt пуст или содержит некорректные данные" << std::endl;
        return 0;
    }
    
    std::ofstream outputFile("energy_report.txt");
    
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка: не удалось создать файл energy_report.txt" << std::endl;
        return 1;
    }
    
    outputFile << std::fixed << std::setprecision(2);
    
    for (const auto& pair : deviceData) {
        const std::string& deviceName = pair.first;
        const std::vector<double>& powerReadings = pair.second;
        
        if (powerReadings.empty()) continue;
        
        double totalPower = std::accumulate(powerReadings.begin(), powerReadings.end(),0.0);
        double averagePower = totalPower / powerReadings.size();
        int measurementsCount = powerReadings.size();
        
        outputFile << deviceName << ": measurements = " << measurementsCount
                  << ", total = " << totalPower << " kWh"
                  << ", average = " << averagePower << " kW" << std::endl;
    }
    
    outputFile.close();
    
    std::cout << "Анализ завершён. Результаты сохранены в energy_report.txt" << std::endl;
    
    return 0;
}