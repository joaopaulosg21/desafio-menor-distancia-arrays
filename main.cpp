#include <iostream>
#include <array>
#include <vector>
#include <bits/stdc++.h>
#include <limits.h>

struct result{
    int posArr;
    int posArr2;
    int min;
};

result calcDistance(std::vector<int> first, std::vector<int> second) {
    result response;
    int min = INT_MAX;
    for(int i=0; i < first.size();i++) {
        for(int j=0; j < second.size();j++) {
            int value;
            if(first[i] < second[j]) {
                value = second[j] - first[i];
            }else if(first[i] > second[j]) {
                value = first[i] - second[j];
            }else {
                value = first[i] - second[j];
                response.posArr = i;
                response.posArr2 = j;
                response.min = value;
                return response;
            }

            if(value < min) {
                response.posArr = i;
                response.posArr2 = j;
                min = value;
                response.min = min;
            }
        }
    }

    return response;
}


int main() {

    std::vector<int> arr = {40,1,45,223,11,15,10,350,200,-4,22};
    std::vector<int> arr2 = {30,91,52,19,8,4,23,13,43,18,40};

    result response = calcDistance(arr,arr2); 
    std::cout << "Valor da menor distancia: " << response.min << + "\n"
    << "Posição do elemento no array 1: " << response.posArr << "\n"
    << "Posição do elemento no array 2: "<< response.posArr2 << "\n";
}