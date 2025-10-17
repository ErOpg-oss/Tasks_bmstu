#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> speeds = {45, 0, 120, 85, 130, 65, 140, 95, 110, 75,
                              150, 55, 125, 70, 135, 80, 160, 90, 115, 100,
                              40, 170, 105, 60, 145, 50, 155, 180, 35, 25,
                              165, 30, 175, 20, 95, 110, 85, 130, 70, 140,
                              65, 150, 55, 120, 80, 135, 90, 125, 75, 95};
    
    std::cout<<"Все скорости: ";
    for (int speed : speeds) {
        std::cout<<speed<<" ";
    }
    std::cout<<std::endl;
    
    
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