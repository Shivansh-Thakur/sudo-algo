// implement selection sort for different containers

#include <iostream>
#include <vector>
#include <utility>

template<typename T>
void selection_sort(std::vector<T>& vec,
		    bool cmp(T, T)=[](T a, T b){return a<b;})
{
  // selected index for sort
  size_t sel;
  
  for(size_t i=0; i<vec.size(); i++) {
    sel = i;

    // search element with cmp
    for(size_t j = i+1; j<vec.size(); j++)
      if (cmp(vec[j], vec[sel])) sel = j;

    // bring selected element to top
    std::swap(vec[i], vec[sel]);
  }
}
