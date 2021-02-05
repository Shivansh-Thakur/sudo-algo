// implement sorting algorithm on STL container vector
// sort according to cmp(ie comparator)

#include <iostream>
#include <vector>
#include <utility>

template <typename T>
void bubble_sort(std :: vector<T> &v,
		 bool cmp(T, T)=[](T a, T b){return a < b;})
{
    // swapped makes sort adaptive which means to stop
    // sorting when list is already sorted
    bool swapped = true;

    // sort from right to left by moving desired bubble to right
    // sorted part
    for(size_t i = 0; i < v.size() && swapped; i++) {
	swapped = false;
	// move bubble to v.size()-i according to cmp
	for(size_t j = 0; j < v.size()-i; j++){
	    if(cmp(v[j+1], v[j])) {
		std::swap(v[j], v[j+1]);
		swapped=true;
	    }
	}
    }
}

template<typename T>
void insertion_sort(std::vector<T>& vec,
		    bool cmp(T, T)=[](T a, T b){return a<b;})
{
    // key will hold element to be inserted to sorted array
    T key;

    // holds index of last sorted element
    long j;

    // sort from left to right by inserting key to left sorted part
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

// perform a heapify down operation for max or min heap
// depending on cmp
template<typename T>
void heapify(std::vector<T>& vec, size_t size, long index, bool cmp(T a, T b))
{
    long root = index, left = 2*index+1, right= 2*index+2;

    // adjust root according to cmp
    if (left < size && cmp(vec[root], vec[left])) root = left;
    if (right < size && cmp(vec[root], vec[right])) root = right;

    // move vec[index] by swapping to desired index
    if (root != index) {
	std::swap(vec[index], vec[root]);
	heapify(vec, size, root, cmp);
    }
}

template<typename T>
void heap_sort(std::vector<T>& vec,
	       bool cmp(T, T)=[](T a, T b){return a<b;})
{
    // build heap by traversing log(vec.size()) nodes
    for (long i=vec.size()/2-1; i>=0; i--) heapify(vec, vec.size(), i, cmp);

    // one by one extract an element from heap
    for (long i=vec.size()-1; i>0; i--) {
	std::swap(vec[0], vec[i]); // move current root to end
	heapify(vec, i, 0, cmp); // heapify according to cmp
    }
}

template<typename T>
T max_element(const std::vector<T> vec)
{
    T max = vec[0];
    
    for(auto i:vec)
	if (i > max) max = i;
    return max;
}


template<typename T>
T min_element(const std::vector<T> vec)
{
    T min = vec[0];
    
    for(auto i:vec)
	if (i < min) min = i;
    return min;
}

// TODO: find a way to incorporate cmp
template<typename T>
void count_sort(std::vector<T>& vec)
{
    if(vec.size() == 0) return;

    // make a counter array of max-min+1 elements
    // to store count on every unique element
    T max, min;
    max = max_element(vec);
    min = min_element(vec);
    long counter[max-min+1];

    // make counter 0
    for(auto i=0; i<max-min+1; i++) counter[i]=0;

    // store element count 
    for(auto i:vec) counter[i-min]++;
	
    long j=0;
    for(long i=min; i<=max; i++) {
	// if counter is positive add element to vec
	while(counter[i-min]) {
	    vec[j++] = i;
	    --counter[i-min];
	}
    }
}
