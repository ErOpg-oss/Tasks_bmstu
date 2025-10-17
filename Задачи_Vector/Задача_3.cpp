#include<iostream>
#include<vector>
#include<algorithm> 
int main() {
    std::vector<int> v(20);

    for(int i = 0; i<20; i++){
        std::cin>>v[i];
    }
    
    auto max_it = std::max_element(v.begin(), v.end(), [](int a, int b) {return a < b;});
    
    std::cout << "Максимум: " << *max_it << "\n";

}