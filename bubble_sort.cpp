#include<iostream>
#include<vector>
#include<utility>

template <typename T>

void bubble_sort(std :: vector<T> &v, bool cmp(T, T)=[](T a, T b){return a < b;}){
    for(size_t i = 0; i < v.size()-1; i++){
        bool swapped = false;
        for(size_t j = 0; j < v.size()-i-1; j++){
            if(cmp(v[j], v[j+1])){
                std :: swap(v[j], v[j+1]);
                swapped = true;
            } 
            if(!swapped) break;
        }
    }
    return;
}
