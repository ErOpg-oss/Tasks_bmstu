#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<climits>

std::vector<double> calculateAverageTemperatures(std::vector<std::vector<double>>& temp) {
    std::vector<double> average(5);

    std::transform(temp.begin(), temp.end(), average.begin(), [](std::vector<double>& v){
        return std::accumulate(v.begin(), v.end(), 0.0)/v.size();
    });

    return average;
}

void findMinMaxPressure(std::vector<std::vector<double>>& pressure) {
    for(int i = 0; i<5; i++){
        auto minmax = std::minmax_element(pressure[i].begin(), pressure[i].end());
        printf("Максимальное значение %d канала давления: %.2f\nМинимальное значение: %.2f\n\n", i, *minmax.second, *minmax.first);
    }
}

std::vector<std::vector<double>> calculateTemperatureDifferences(std::vector<std::vector<double>>& temp) {
    std::vector<std::vector<double>> temp_diff(5);

    for(int i = 0; i<5; i++){
        std::transform(temp[i].begin()+1, temp[i].end(), temp[i].begin(), std::back_inserter(temp_diff[i]), [](double a, double b){
            return a-b;
        });
    }

    return temp_diff;
}

double findMaxTemperatureDifference(std::vector<std::vector<double>>& temp) {
    double Maxi = INT_MIN;

    for(int i = 0; i<5; i++){
        auto minmax = std::minmax_element(temp[i].begin(), temp[i].end());
        double diff = *minmax.second - *minmax.first;
        if(Maxi < diff) Maxi = diff;
    }

    return Maxi;
}

std::vector<std::vector<double>> normalizePressure(std::vector<std::vector<double>>& pressure) {
    std::vector<std::vector<double>> norm_pressure(5);

    for(int i = 0; i<5; i++){
        auto minmax = std::minmax_element(pressure[i].begin(), pressure[i].end());
        norm_pressure[i].resize(pressure[i].size());

        std::transform(pressure[i].begin(), pressure[i].end(), norm_pressure[i].begin(), [minmax](double value){
            return ((value - *minmax.first)/(*minmax.second - *minmax.first));
        });
    }

    return norm_pressure;
}

void printPressurePeaks(std::vector<std::vector<double>>& norm_pressure) {
    printf("Пики давления (>0.9):\n");

    std::for_each(norm_pressure.begin(), norm_pressure.end(), [](std::vector<double>& vec){
        std::for_each(vec.begin(), vec.end(), [](double x){
            if(x>0.9) std::cout << x << " ";
        });
    });

    std::cout << std::endl;
}

void analyzeAverageTemperatures(std::vector<double>& average) {
    auto max_it = std::max_element(average.begin(), average.end());
    int max_channel = std::distance(average.begin(), max_it);

    printf("Канал с максимальной средней температурой: %d\n", max_channel);

    std::sort(average.begin(), average.end());

    printf("Отсортированные средние температуры: ");

    std::for_each(average.begin(), average.end(), [](double x){ std::cout << x << " "; });

    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<double>> temp(5,std::vector<double>(30));
    std::vector<std::vector<double>> pressure(5,std::vector<double>(100));
    
    for(int i = 0; i<5; i++){
        for(int j = 0; j<30; j++){
            std::cin>>temp[i][j];
        }
    }

    for(int i = 0; i<5; i++){
        for(int j = 0; j<100; j++){
            std::cin>>pressure[i][j];
        }
    }

    std::vector<double> average = calculateAverageTemperatures(temp);

    printf("Средняя температура по каналам:\n");

    std::for_each(average.begin(), average.end(), [](double x){ std::cout << x << " "; });

    std::cout<<std::endl;

    findMinMaxPressure(pressure);

    std::vector<std::vector<double>> temp_diff = calculateTemperatureDifferences(temp);

    printf("Разности между соседними измерениями для температуры:\n");

    std::for_each(temp_diff.begin(), temp_diff.end(), [](std::vector<double>& vec){
        std::for_each(vec.begin(), vec.end(), [](double x){ std::cout << x << " "; });
        std::cout << std::endl;
    });

    std::cout<<std::endl;

    double maxDiff = findMaxTemperatureDifference(temp);

    printf("Максимальная разница max-min температуры: %.2f\n", maxDiff);


    std::vector<std::vector<double>> norm_pressure = normalizePressure(pressure);

    printf("Нормализованные значения давления:\n");

    std::for_each(norm_pressure.begin(), norm_pressure.end(), [](std::vector<double>& vec){
        std::for_each(vec.begin(), vec.end(), [](double x){ std::cout << x << " "; });
        std::cout << std::endl;
    });

    printPressurePeaks(norm_pressure);

    analyzeAverageTemperatures(average);

    return 0;
}