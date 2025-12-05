#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    const char* FILE_NAME = "vibration_log.txt";
    const char* OUTPUT_FILE_NAME = "vibration_report.txt";

    std::fstream file(FILE_NAME, std::ios::in);

    if (file.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }

    double inp{};
    std::vector<double> original_data{};
    std::vector<double> data{};
    
    while (file >> inp) {
        original_data.push_back(inp);
    }

    file.close();

    if (original_data.empty()) {
        std::cout << "File is empty" << std::endl;
        return 0;
    }

    data = original_data;
    
    std::fstream file_out(OUTPUT_FILE_NAME, std::ios::out);

    file_out << std::fixed << std::setprecision(4);
    
    file_out << "Количество измерений: " << original_data.size() << std::endl;
    
    data.erase(std::remove_if(data.begin(), data.end(), 
               [](const double& x){ return x <= 0.05; }), 
               data.end());

    auto findAverage = [](std::vector<double>& vec){
        if (vec.empty()) return 0.0;
        double sm{};
        for (double& x : vec) sm += x;
        return sm / vec.size();
    };

    auto findMax = [](std::vector<double>& vec){
        if (vec.empty()) return 0.0;
        double max{vec[0]};
        for (double& x : vec) {
            if (x > max) max = x;
        }
        return max;
    };

    auto findMin = [](std::vector<double>& vec){if (vec.empty()) return 0.0;
        double min{vec[0]};
        for (double& x : vec) {
            if (x < min) min = x;
        }
        return min;
    };

    file_out << "Фильтрованные значения (>0.05): ";
    for (double& x : data) file_out << std::setprecision(2) << x << ' ';
    file_out << std::endl;
    
    file_out << std::setprecision(4);
    file_out << "Среднее значение: " << findAverage(data) << std::endl;
    
    if (!data.empty()) {
        file_out << "Минимум: " << std::setprecision(2) << findMin(data) << std::endl;
        file_out << "Максимум: " << std::setprecision(2) << findMax(data) << std::endl;
    } else {
        file_out << "Минимум: нет значений >0.05" << std::endl;
        file_out << "Максимум: нет значений >0.05" << std::endl;
    }

    file_out.close();

    std::cout << "Анализ вибрационных данных завершён. Отчёт сохранён в " << OUTPUT_FILE_NAME << std::endl;

    return 0;
}