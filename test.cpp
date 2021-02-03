#include "selection_sort.h"
#include "insertion_sort.h"
#include <exception>

using namespace std;

// wrapper to print vector
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
  for(auto i:vec) cout << i << " ";
  return os;
}

bool is_less(int a, int b) { return a<b;}

bool is_more(int a, int b) { return a>b;}

// TODO: use a function: func_name(sorting_type)

// test selection sort
void test1()
{
  vector<int> v0{0, 22, 3, 2, 21};
  selection_sort(v0);
  cout << "v0 = " << v0 << "\n";
  
  // test large input
  vector<int> v1;
  for(int i=1000; i>0; i--) v1.push_back(i);
  // selection_sort(v1);
  // cout << "v1 = " << v1 << "\n";

  // test 0 as input
  vector<int> v2;
  selection_sort(v2);
  cout << "v2 = " << v2 << "\n";

  // test negative numbers
  vector<int> v3;
  for(int i=-1; i>-11; i--) v3.push_back(i);
  selection_sort(v3);
  cout << "v3 = " << v3 << "\n";

  // test 1's as input
  vector<int> v4{1, 1, 1, 1, 1};
  selection_sort(v4);
  cout << "v4 = " << v4 << "\n";

  // test 0's as input
  vector<int> v5(10);
  selection_sort(v5, is_more);
  cout << "v5 = " << v5 << "\n";

  // test 0's and 1's
  vector<int> v6;
  for(int i=0; i<10; i++) {
    if(i%2 == 0) v6.push_back(1);
    else v6.push_back(0);
  }
  selection_sort(v6, is_more);
  cout << "v6 = " << v6 << "\n";
}

// test insertion sort
void test2()
{
  vector<int> v0{0, 22, 3, 2, 21};
  insertion_sort(v0);
  cout << "v0 = " << v0 << "\n";
  
  // test large input
  vector<int> v1;
  for(int i=1000; i>0; i--) v1.push_back(i);
  insertion_sort(v1);
  // cout << "v1 = " << v1 << "\n";

  // test 0 as input
  vector<int> v2;
  insertion_sort(v2);
  cout << "v2 = " << v2 << "\n";

  // test negative numbers
  vector<int> v3;
  for(int i=-1; i>-11; i--) v3.push_back(i);
  insertion_sort(v3);
  cout << "v3 = " << v3 << "\n";

  // test 1's as input
  vector<int> v4{1, 1, 1, 1, 1};
  insertion_sort(v4);
  cout << "v4 = " << v4 << "\n";

  // test 0's as input
  vector<int> v5(10);
  // insertion_sort(v5);
  cout << "v5 = " << v5 << "\n";

  // test 0's and 1's
  vector<int> v6;
  for(int i=0; i<10; i++) {
    if(i%2 == 0) v6.push_back(1);
    else v6.push_back(0);
  }
  insertion_sort(v6, is_more);
  cout << "v6 = " << v6 << "\n";
}

int main()
  try {
    test2();
    return 0;
  }
  catch(exception& e) {
    cerr << "Error: " << e.what();
    return 1;
  }
  catch(...) {
    cerr << "Oops! unknown exception";
    return 2;
  }
