#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<double> energy = {45.5,38.2,52.1,41.8,67.3,55.6,72.8,48.9,59.4,63.7,44.2,51.9,69.5,57.1,42.8,65.3,53.7,47.6,71.2,60.8,39.4,68.9,56.3,49.7,64.1,54.2,43.9,58.6,62.4,46.8};
    
    std::cout<<"Потребление энергии за 30 дней: ";
    for(double i:energy){std::cout<<i<<" ";}
    std::cout<<std::endl;
    
    double total=std::accumulate(energy.begin(),energy.end(),0.0);
    std::cout<<"Общее потребление за месяц: "<<total<<" кВт·ч"<<std::endl;
    
    double average=total/energy.size();
    std::cout<<"Среднесуточное потребление: "<<average<<" кВт·ч"<<std::endl;
    
    auto max_it=std::max_element(energy.begin(),energy.end());
    auto min_it=std::min_element(energy.begin(),energy.end());
    std::cout<<"Максимальное потребление: "<<*max_it<<" кВт·ч (день "<<(max_it-energy.begin()+1)<<")"<<std::endl;
    std::cout<<"Минимальное потребление: "<<*min_it<<" кВт·ч (день "<<(min_it-energy.begin()+1)<<")"<<std::endl;
    
    double cof=average*1.2;
    std::vector<double> peak;
    for(double e:energy){
        if(e>cof){peak.push_back(e);}
    }
    
    std::cout<<"Пиковые дни >20% от среднего: ";
    for(double i:peak){std::cout<<i<<" ";}
    std::cout<<std::endl;
    
    return 0;
}