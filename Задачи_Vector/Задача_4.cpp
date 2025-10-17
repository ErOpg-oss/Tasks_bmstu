#include<iostream>
#include<vector>
#include<algorithm> 
int main() {
    std::vector<int> v = {1, -24, 33, -1, 5, 8, -12, 78};
    
    v.erase(std::remove_if(v.begin(), v.end(), [](int x){ return x < 0; }), v.end());
    
    
    for (int x : v) std::cout << x << " ";
}