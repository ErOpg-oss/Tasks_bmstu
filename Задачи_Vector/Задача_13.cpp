#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<double> pressure = {2.1,7.8,5.5,9.2,3.4,8.9,4.7,6.3,10.1,1.8,2.9,7.1,5.9,8.5,3.8,9.8,4.2,6.8,10.5,1.5,2.7,7.5,5.2,8.7,3.9,9.5,4.5,6.5,10.8,1.2,2.5,7.9,5.8,8.3,3.7,9.9,4.8,6.9,10.2,1.9,2.8,7.2,5.7,8.6,3.5,9.6,4.9,6.7,10.3,1.7};
    
    std::cout<<"Давление в трубопроводе: ";
    for(double i:pressure){std::cout<<i<<" ";}
    std::cout<<std::endl;
    
    pressure.erase(std::remove_if(pressure.begin(),pressure.end(),[](double x){return x<0||x>12;}),pressure.end());
    
    std::cout<<"После удаления ошибок: ";
    for(double i:pressure){std::cout<<i<<" ";}
    std::cout<<std::endl;
    
    double average=std::accumulate(pressure.begin(),pressure.end(),0.0)/pressure.size();
    std::cout<<"Среднее давление: "<<average<<" бар"<<std::endl;
    
    auto minmax=std::minmax_element(pressure.begin(),pressure.end());
    std::cout<<"Минимальное давление: "<<*minmax.first<<std::endl;
    std::cout<<"Максимальное давление: "<<*minmax.second<<std::endl;
    
    std::cout<<"Значения >8: ";
    std::for_each(pressure.begin(),pressure.end(),[](double x){if(x>8){std::cout<<x<<" ";}});
    std::cout<<std::endl;
    
    return 0;
}