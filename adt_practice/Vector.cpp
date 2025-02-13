#include <iostream>
using namespace std;

template <class T>
class Vector{
    private:
        T *_arr;
        int _capacity;
        int _size;
        const int SIZE_MULTIPLIER = 2;

        void revise_capacity(int new_capacity){
            T *new_arr = new T[new_capacity];
            for(int i = 0; i<_size; i++ ){
                new_arr[i] = _arr[i];
            }
            delete []_arr;
            _arr = new_arr;
            _capacity = new_capacity;
        }
    public:
        Vector(int capacity = 1){
            _capacity = capacity;
            _size = 0;
            _arr = new T[_capacity];
        }
        ~Vector(){
            delete []_arr;
        }
        int get_capacity() const{
            return _capacity;
        }
        
        int get_size() const{
            return _size;
        }

        void append(const T &val){
            if(_size==_capacity){
                revise_capacity(_capacity * SIZE_MULTIPLIER);
            }
            _arr[_size] = val;
            _size++;
        }

        T remove_last(){
            T val = _arr[_size-1];
            _size--;
            if(_size<_capacity/SIZE_MULTIPLIER){
                revise_capacity(_capacity/SIZE_MULTIPLIER);
            }
            return val;
        }
        
        void printd(){
            cout << "Size: "<< _size << " Capacity: " << _capacity << '\n';
            cout << "[";
            for(int i = 0; i < _size;i++){
                cout << '\t' << _arr[i];
            }
            cout << "]\n";
        }
};

int main(){
    int ele = 0;
    Vector<int> v1(1);
    v1.printd();
    v1.append(6);
    v1.printd();
    v1.append(7);
    v1.printd();
    v1.append(-1);
    v1.printd();
    v1.append(-1);
    v1.printd();
    ele = v1.remove_last();
    v1.printd();
    ele = v1.remove_last();
    v1.printd();
    ele = v1.remove_last();
    v1.printd();
    ele = v1.remove_last();
    
    return 1;
}