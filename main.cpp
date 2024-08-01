#include <iostream>
#include <array>
#include <vector>
#include <bits/stdc++.h>

struct result{
    int posArr;
    int posArr2;
    int min;
};

result calcDistance(std::array<int,10> first, std::array<int,10> second) {
    result response;
    int menor = second[0] - first[0];

    for(int i=0; i < first.size();i++) {
        for(int j=0; j < second.size();j++) {
            int value;
            if(first[i] < second[j]) {
                value = second[j] - first[i];
            }else if(first[i] > second[j]) {
                value = first[i] - second[j];
            }else {
                menor = first[i] - second[j];
            }

            if(value < menor) {
                response.posArr = i;
                response.posArr2 = j;
                menor = value;
                response.min = menor;
            }
        }
    }

    return response;
}


int main() {

    std::array<int, 10> arr = {5,40,1,45,223,11,15,10,9,350};
    std::array<int, 10> arr2 = {30,91,52,19,8,4,2,13,43,18};

    result response = calcDistance(arr,arr2); 
    std::cout << "Posição do elemento no array 1: " << response.posArr << "\n"
    << "Posição do elemento no array 2: "<< response.posArr2 << "\n"
    << "Valor da menor distancia: " << response.min << + "\n";
}