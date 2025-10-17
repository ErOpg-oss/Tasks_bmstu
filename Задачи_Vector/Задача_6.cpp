#include<iostream>
#include<vector>
#include<numeric> 
#include<algorithm> 
int main() {
    std::vector<int> v(20);

    for(int i = 0; i<20; i++){
        std::cin>>v[i];
    }

    auto it = std::find(v.begin(), v.end(), 7);
    if (it != v.end()) {
        std::cout << "Число 7 найдено" << std::endl;
    } else {
        std::cout << "Число 7 не найдено" << std::endl;
    }


    std::sort(v.begin(), v.end()); 
    v.erase(std::unique(v.begin(), v.end()), v.end()); 

    for(int i = 0; i<v.size(); i++){
        std::cout<<v[i]<<std::endl;
    }

}
