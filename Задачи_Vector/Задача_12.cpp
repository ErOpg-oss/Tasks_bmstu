#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<double> fuel = {85.0,84.2,83.5,82.8,81.9,81.1,80.3,79.6,78.9,78.1,77.4,76.8,76.1,75.3,74.7,74.0,73.4,72.8,72.1,71.5,70.9,70.3,69.7,69.1,68.5,67.9,67.3,66.8,66.2,65.7,65.1,64.6,64.0,63.5,63.0,62.5,62.0,61.5,61.0,60.5,60.0,59.5,59.0,58.6,58.1,57.7,57.2,56.8,56.3,55.9};
    
    std::cout<<"Уровень топлива: ";
    for(double i:fuel){std::cout<<i<<" ";}
    std::cout<<std::endl;
    
    auto min_it=std::min_element(fuel.begin(),fuel.end());
    std::cout<<"Минимальный уровень: "<<*min_it<<"%"<<std::endl;
    
    auto max_it=std::max_element(fuel.begin(),fuel.end());
    double cof=*max_it*0.05;
    bool below_cof=false;
    for(double i:fuel){
        if(i<cof){
            below_cof=true;
            break;
        }
    }
    
    if(below_cof){std::cout<<"Уровень падал ниже 5%: да"<<std::endl;}
    else{std::cout<<"Уровень падал ниже 5%: нет"<<std::endl;}
    
    double consumption=fuel[0]-fuel[fuel.size()-1];
    std::cout<<"Среднее потребление: "<<consumption<<"%"<<std::endl;
    
    std::sort(fuel.begin(),fuel.end());
    
    double median;
    if(fuel.size()%2==0){
        median=(fuel[fuel.size()/2-1]+fuel[fuel.size()/2])/2.0;
    }else{
        median=fuel[fuel.size()/2];
    }
    std::cout<<"Медиана: "<<median<<std::endl;
    
    return 0;
}