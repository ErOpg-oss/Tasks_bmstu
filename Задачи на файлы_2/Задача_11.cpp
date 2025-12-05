#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

int main() {
    std::ifstream f("sensor_data.txt");
    std::vector<double> temperatures;
    double temp;
    
    // Чтение данных
    while (f >> temp) {
        temperatures.push_back(temp);
    }
    f.close();
    
    std::cout << "Прочитано значений: " << temperatures.size() << "\n";
    
    // Фильтрация некорректных значений (-50 до +50)
    auto end = std::remove_if(temperatures.begin(), temperatures.end(),
        [](double x) { return x < -50.0 || x > 50.0; });
    
    temperatures.erase(end, temperatures.end());
    
    std::cout << "После фильтрации: " << temperatures.size() << " значений\n";
    
    // Вычисление средней температуры
    double sum = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
    double average = sum / temperatures.size();
    
    // Сохранение отфильтрованных данных
    std::ofstream out("filtered_sensor_data.txt");
    for (double t : temperatures) {
        out << std::fixed << std::setprecision(2) << t << "\n";
    }
    out.close();
    
    // Вывод результатов
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Средняя температура: " << average << "°C\n";
    std::cout << "Отфильтрованные данные сохранены в filtered_sensor_data.txt\n";
    
    return 0;
}
