#include<iostream>
#include<vector>
#include<algorithm>
int main() {
    std::vector<int> v(10);
    for(int i =0; i<10; i++) {v[i]= i + 1;}

    std::for_each(v.begin(), v.end(), [](int& x){x *= 2;});
    for (int i : v) {
        std::cout << i << " ";
    }
    return 0;
}