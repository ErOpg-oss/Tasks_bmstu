#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>

int main() {
    int n;
    std::vector<double> temperatures;

    std::cout<<"Введиет кол-во данных температур";
    std::cin>>n;
     
    for(int i = 0; i < n; i++) {
        double temp;
        std::cin >> temp;
        temperatures.push_back(temp);
    }

    temperatures.erase(std::remove_if(temperatures.begin(), temperatures.end(), [](double temp) {return abs(temp)>50.0;}),temperatures.end());
    
    std::cout << "После фильтрации [-50, 50]: ";
    for(double temp : temperatures) {
        std::cout << temp << " ";
    }
    std::cout << std::endl;
    
    double sum = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
    double average = sum / temperatures.size();
    std::cout << "Средняя температура: " << average << std::endl;
    
    auto min_it = std::min_element(temperatures.begin(), temperatures.end());
    std::cout << "Минимальная температура: " << *min_it << std::endl;
    
    
    auto max_it = std::max_element(temperatures.begin(), temperatures.end());
    std::cout << "Максимальная температура: " << *max_it << std::endl;
    
    bool bigger10 = true;
    for_each(temperatures.begin(), temperatures.end(), [&bigger10](int x) {if (x <= 10) {bigger10 = false;}});
    if (bigger10) std::cout<<"Все элементы больше 10";
    else std::cout<<"Не все элементы больше 10";
    
    
    return 0;
}
