#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<double> speeds(50);

    std::cout<<"Введиет кол-во данных температур:"<<std::endl;
     
    for(int i = 0; i < 50; i++) {
        double speed;
        std::cin >> speed;
        speeds.push_back(speed);
    }

    std::vector<int> overspeeds;
    auto filter = [](int speed) {return speed > 120;};
    for (int speed : speeds) {
        if (filter(speed)) {
            overspeeds.push_back(speed);
        }
    }
    
    std::cout<<"Превышения скорости >120: ";
    for (int speed : overspeeds) {std::cout<<speed<<" ";}
    std::cout<<std::endl;
    
    double  average = std::accumulate(speeds.begin(), speeds.end(), 0.0) / speeds.size();
    std::cout<<"Средняя скорость: "<<average<<std::endl;
    
   
    bool allbigger_0 = std::all_of(speeds.begin(), speeds.end(),[](int speed){return speed > 0;});
    if (allbigger_0) std::cout<<"Все скорости больше 0";
    else std::cout<<"Не все скорости больше 0";

    std::cout<<std::endl;
    
    std::sort(speeds.begin(), speeds.end());
    
    std::cout<<"10 максимальных значений скорости ";
    for (int i = speeds.size() - 10; i<speeds.size(); i++) {
        std::cout<<speeds[i]<<" ";
    }
    std::cout <<std::endl;
    
    return 0;
}