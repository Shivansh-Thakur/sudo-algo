// implement insertion sort

#include <iostream>
#include <vector>
#include <utility>

template<typename T>
void insertion_sort(std::vector<T>& vec,
		    bool cmp(T, T)=[](T a, T b){return a<b;})
{
  // key will hold element to be inserted to sorted array
  T key;

  long j; // j can be -1
  for(size_t i=1; i<vec.size(); i++) {
    j = i-1;
    key = vec[i];

    // look for preferred position to insert key in
    // already sorted left array
    while(j>=0 && cmp(key, vec[j])) {
      vec[j+1] = vec[j];
      --j;
    }
    vec[j+1] = key; // insert key
  }
}
