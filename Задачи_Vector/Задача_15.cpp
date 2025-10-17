#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<climits>

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

    //1
    std::vector<double> average(5);

    std::transform(temp.begin(), temp.end(), average.begin(), [](std::vector<double>& v){
        return std::accumulate(v.begin(), v.end(), 0.0)/v.size();
    });

    printf("Средняя температура по каналам:\n");

    std::for_each(average.begin(), average.end(), [](double x){ std::cout << x << " "; });

    std::cout<<std::endl;

    //2
    for(int i = 0; i<5; i++){
        auto minmax = std::minmax_element(pressure[i].begin(), pressure[i].end());
        printf("Максимальное значение %d канала давления: %.2f\n", i, *minmax.second);
        printf("Минимальное значение: %.2f\n\n", i, *minmax.first);
    }

    //3
    std::vector<std::vector<double>> temp_diff(5);

    for(int i = 0; i<5; i++){
        for(int j = 1; j < 30; j++) {
            temp_diff[i].push_back(temp[i][j] - temp[i][j-1]);
        }
    }

    printf("Разности между соседними измерениями для температуры:\n");

    std::for_each(temp_diff.begin(), temp_diff.end(), [](std::vector<double>& vec){
        std::for_each(vec.begin(), vec.end(), [](double x){ std::cout << x << " "; });
        std::cout << std::endl;
    });

    std::cout<<std::endl;

    //4
    double Maxi = INT_MIN;

    for(int i = 0; i<5; i++){
        auto minmax = std::minmax_element(temp[i].begin(), temp[i].end());
        double diff = *minmax.second - *minmax.first;
        if(Maxi < diff) Maxi = diff;
    }

    printf("Максимальная разница max-min температуры: %.2f\n", Maxi);

    //5
    std::vector<std::vector<double>> norm_pressure(5);

    for(int i = 0; i<5; i++){
        auto minmax = std::minmax_element(pressure[i].begin(), pressure[i].end());
        norm_pressure[i].resize(pressure[i].size());

        std::transform(pressure[i].begin(), pressure[i].end(), norm_pressure[i].begin(), [minmax](double value){
            return ((value - *minmax.first)/(*minmax.second - *minmax.first));
        });
    }

    printf("Нормализованные значения давления:\n");

    std::for_each(norm_pressure.begin(), norm_pressure.end(), [](std::vector<double>& vec){
        std::for_each(vec.begin(), vec.end(), [](double x){ std::cout << x << " "; });
        std::cout << std::endl;
    });

    //6
    printf("Пики давления (>0.9):\n");

    std::for_each(norm_pressure.begin(), norm_pressure.end(), [](std::vector<double>& vec){
        std::for_each(vec.begin(), vec.end(), [](double x){
            if(x>0.9) std::cout << x << " ";
        });
    });

    std::cout << std::endl;

    //7
    auto max_it = std::max_element(average.begin(), average.end());
    int max_channel = std::distance(average.begin(), max_it);

    printf("Канал с максимальной средней температурой: %d\n", max_channel);

    std::sort(average.begin(), average.end());

    printf("Отсортированные средние температуры: ");

    std::for_each(average.begin(), average.end(), [](double x){ std::cout << x << " "; });

    std::cout << std::endl;

    return 0;
}
