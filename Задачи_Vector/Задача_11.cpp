#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<double> vibration = {0.05,0.8,0.12,1.2,0.03,0.6,0.9,0.08,1.5,0.7,0.04,0.85,1.1,0.09,0.65,1.3,0.07,0.75,1.4,0.06,0.95,0.11,1.6,0.02,0.55,1.7,0.15,0.5,1.1,0.13,0.88,1.8,0.17,0.72,1.9,0.19,0.68,2.0,0.14,0.78,0.16,0.92,0.18,0.81,0.21,0.63,0.22,0.58,0.24,0.66};
    
    std::cout<<"Амплитуды вибрации: ";
    for(double i:vibration){std::cout<<i<<" ";}
    std::cout<<std::endl;
    
    vibration.erase(std::remove_if(vibration.begin(),vibration.end(),[](double x){return x<0.1;}),vibration.end());
    
    std::cout<<"После удаления шумов: ";
    for(double i:vibration){std::cout<<i<<" ";}
    std::cout<<std::endl;
    
    double average=std::accumulate(vibration.begin(),vibration.end(),0.0)/vibration.size();
    auto max_it=std::max_element(vibration.begin(),vibration.end());
    
    std::cout<<"Средняя амплитуда: "<<average<<std::endl;
    std::cout<<"Максимальная амплитуда: "<<*max_it<<std::endl;
    
    bool all_above=true;
    for(double i:vibration){
        if(i<0.5){
            all_above=false;
            break;
        }
    }
    
    if(all_above){std::cout<<"Все значения превышают 0.5: да"<<std::endl;}
    else{std::cout<<"Все значения превышают 0.5: нет"<<std::endl;}
    
    std::sort(vibration.begin(),vibration.end());
    
    std::cout<<"10 наибольших амплитуд: ";
    size_t start=(vibration.size()>10)?vibration.size()-10:0;
    for(size_t i=start;i<vibration.size();i++){std::cout<<vibration[i]<<" ";}
    std::cout<<std::endl;
    
    return 0;
}