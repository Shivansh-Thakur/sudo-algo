// implement selection sort for different containers

#include <iostream>
#include <vector>
#include <utility>

// TODO: implement both ascending and descending order
template<typename T>
void selection_sort(std::vector<T>& vec)
{
  size_t min;
  
  for(size_t i=0; i<vec.size(); i++) {
    min = i;

    // search for smallest element 
    for(size_t j = j+1; j<vec.size(); j++)
      if (vec[j] < vec[min]) min = j;

    // bring smallest to top
    std::swap(vec[i], vec[min]);
  }
}
