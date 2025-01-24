#include <iostream>
#include <algorithm>
#include <random>    // for std::default_random_engine
using namespace std;
#include <chrono>       // std::chrono::system_clock  s

void print(int a[], int size){
  for(int i = 0;i<size;i++){
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int main() 
{
    int a[] = {1,3,2};
    print(a, 3);
    
     unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
              shuffle(begin(a), a[2], default_random_engine(seed));
    print(a,3);
    
    cout << "Hello, World!";
    return 0;
}