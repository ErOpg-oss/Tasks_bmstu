#include<iostream>
#include<vector>
#include<numeric> 
#include<algorithm> 
int main() {
    std::vector<int> v(20);

    for(int i = 0; i<20; i++){
        std::cin>>v[i];
    }
    auto max_it = std::max_element(v.begin(), v.end());
    auto min_it = std::min_element(v.begin(), v.end());
    std::cout<<"Максимальное число: "<<*max_it<<std::endl;
    std::cout<<"Минимальное число: "<<*min_it<<std::endl;


    int sum = std::accumulate(v.begin(), v.end(), 0);
    int average = sum/v.size();


    std::cout << "Среднее значение: " << average << "\n";


    std::sort(v.begin(), v.end());
    double median;
    median = (v[(v.size() / 2) - 1] + v[v.size() / 2]) / 2.0;
    
    std::cout << "Медиана: " << median << std::endl;

}