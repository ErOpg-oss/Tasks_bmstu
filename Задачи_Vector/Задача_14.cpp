#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<double> consumption = {150,280,320,190,410,380,290,240,360,420,390,370,340,310,260,230,350,440,400,330,270,250,200,180};
    
    std::cout<<"Потребление за сутки: ";
    for(double i:consumption){std::cout<<i<<" ";}
    std::cout<<std::endl;
    
    double total=std::accumulate(consumption.begin(),consumption.end(),0.0);
    double average=total/consumption.size();
    std::cout<<"Суммарное потребление: "<<total<<" кВт·ч"<<std::endl;
    std::cout<<"Среднее потребление: "<<average<<" кВт·ч"<<std::endl;
    
    auto max_it=std::max_element(consumption.begin(),consumption.end());
    std::cout<<"Пиковое потребление: "<<*max_it<<" кВт·ч (час "<<(max_it-consumption.begin()+1)<<")"<<std::endl;
    
    std::vector<double> deviation;
    std::transform(consumption.begin(),consumption.end(),std::back_inserter(deviation),[average](double x){return x-average;});
    
    std::cout<<"Отклонения от среднего: ";
    for(double i:deviation){std::cout<<i<<" ";}
    std::cout<<std::endl;
    
    std::sort(consumption.begin(),consumption.end());
    
    std::cout<<"Топ-5 минимальных часов: ";
    for(int i=0;i<5;i++){std::cout<<consumption[i]<<" ";}
    std::cout<<std::endl;
    
    return 0;
}