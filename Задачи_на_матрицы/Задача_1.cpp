#include <iostream>

int main(){
    int n;
    std::cin>>n;
    
    int array[n][n];

    
    int M1[n][n], M2[n][n], M3[n][n], M4[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) std::cin>>array[i][j];
    }
    std::cout<<std::endl;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M1[i][j] = array[j][i];                  
            M2[i][j] = array[n-1-j][n-1-i];          
            M3[i][j] = array[i][n-1-j];              
            M4[i][j] = array[n-1-i][j];              
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout<<M1[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout<<M2[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout<<M3[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout<<M4[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    
    bool found = false;
    bool eq12 = true, eq13 = true, eq14 = true;
    bool eq23 = true, eq24 = true, eq34 = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M1[i][j] != M2[i][j]) eq12 = false;
            if (M1[i][j] != M3[i][j]) eq13 = false;
            if (M1[i][j] != M4[i][j]) eq14 = false;
            if (M2[i][j] != M3[i][j]) eq23 = false;
            if (M2[i][j] != M4[i][j]) eq24 = false;
            if (M3[i][j] != M4[i][j]) eq34 = false;
            }
        }   
    
    if (eq12) {
        std::cout<<"(1, 2)" << std::endl; 
        found = true;
        std::cout<<std::endl;
    } 
    if (eq13){
        std::cout<<"(1, 3)" << std::endl; 
        found = true;
        std::cout<<std::endl;
    } 
    if (eq14){
        std::cout<<"(1, 4)" << std::endl; 
        found = true; 
        std::cout<<std::endl;
    }
    if (eq23){
        std::cout<<"(2, 3)" << std::endl; 
        found = true;
        std::cout<<std::endl;
    }
    if (eq24){
        std::cout<<"(2, 4)" << std::endl; 
        found = true;
        std::cout<<std::endl;
    }
    if (eq34){
        std::cout<<"(3, 4)" << std::endl; 
        found = true; 
    }

    if (!found) {
        std::cout<<"NONE" << std::endl;
    }

    return 0;
}