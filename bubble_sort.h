// implement bubble sort

#include<iostream>
#include<vector>
#include<utility>

template <typename T>
void bubble_sort(std :: vector<T> &v, bool cmp(T, T)=[](T a, T b){return a < b;})
{
    bool swapped = true;
    for(size_t i = 0; i < v.size() && swapped; i++) {
	swapped = false;
	for(size_t j = 0; j < v.size()-i; j++){
	    if(cmp(v[j+1], v[j])) {
		std::swap(v[j], v[j+1]);
		swapped=true;
	    } 
	}
    }
}
