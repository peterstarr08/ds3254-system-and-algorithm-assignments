#include <iostream>


using namespace std;

class MaxHeap{
    private:
        const int EMPTY_NODE = -1;

        int *_array;
        int _size;

        void increaseArraySize(){
            int *_newArray = new int[_size + 1];
            for(int i = 0;i<_size;i++){
                _newArray[i] = _array[i];
            }
            _size++;
            delete [] _array;
            _array = _newArray;
        }

        int indexOfFirstLeafNode(){
            return _size/2;
        }

        bool isLeafNodeOrOutOfBounds(int index){
            if(index>=indexOfFirstLeafNode()){
                return true;
            }
            return false;
        }

        int getParentIndex(int index){
            return (index - 1)/2;
        }
        
        int getLeftChildIndex(int index){
            // if( 2*index +1 >= _size){
            //     return EMPTY_NODE;
            // }
            return 2*index +1;
        }

        int getRightChildIndex(int index){
            // if( 2*index + 2 >= _size){
            //     return EMPTY_NODE;
            // }
            return 2*index + 2;
        }

        int getMaxofFirstLevelSubtree(const int &index){
            if(index>=_size){
                throw runtime_error("Out of bounds!");
            }
            int leftChildIndex = getLeftChildIndex(index)>=_size?EMPTY_NODE:getLeftChildIndex(index);
            int rightChildIndex = getRightChildIndex(index)>=_size?EMPTY_NODE:getRightChildIndex(index);
            if(leftChildIndex==EMPTY_NODE && rightChildIndex==EMPTY_NODE){
                return _array[index];
            }
            else if(leftChildIndex==EMPTY_NODE){
                return max(_array[index], _array[rightChildIndex]);
            }
            else if(rightChildIndex==EMPTY_NODE){
                return max(_array[index], _array[leftChildIndex]);
            }

            return max(max(_array[leftChildIndex], _array[rightChildIndex]), _array[index]);

        }

        int getMaxChildIndex(const int &index){
            int leftChildIndex = getLeftChildIndex(index)>=_size?EMPTY_NODE:getLeftChildIndex(index);
            int rightChildIndex = getRightChildIndex(index)>=_size?EMPTY_NODE:getRightChildIndex(index);
            if(leftChildIndex==EMPTY_NODE && rightChildIndex==EMPTY_NODE){
                return EMPTY_NODE;
            }
            else if(leftChildIndex==EMPTY_NODE){
                return rightChildIndex;
            }
            else if(rightChildIndex==EMPTY_NODE){
                return leftChildIndex;
            }

            return (_array[leftChildIndex]>=_array[rightChildIndex])?leftChildIndex:rightChildIndex;
        }

        bool isLeftChildLeafNode(int index){
            return isLeafNodeOrOutOfBounds(getLeftChildIndex(index));
        }

        bool isRightChildLeafNode(int index){
            return isLeafNodeOrOutOfBounds(getRightChildIndex(index));
        }

        void buildHeap(int size){
            for(int i = size/2 - 1;i>=0;i--){
                maxHeapify(i);
            }   
        }


    public:
        MaxHeap(const int& size){
            _size = size;
            _array = new int[size];
        }
        MaxHeap(const int& size, const int *array, bool heapify = false){
            _size = size;
            _array = new int[size];
            for(int i = 0;i<_size;i++){
                _array[i] = array[i];
            }

            if(heapify){
                buildHeap(_size);
            }
        }
        ~MaxHeap(){
            delete[] _array;
        }

        void maxHeapify(int index){//left and right childs of index are alrady a Max Heap
            while((!isLeafNodeOrOutOfBounds(index)) && _array[index]!=getMaxofFirstLevelSubtree(index)){
                int maxChildIndex = getMaxChildIndex(index);
                int _temp = _array[maxChildIndex];
                _array[maxChildIndex] = _array[index];
                _array[index] = _temp;
                index = maxChildIndex;
            }
        }

        int maxOfHeap(){
            return _array[0];
        }

        int removeMax(){
            int temp = _array[0];
            _array[0] = _array[_size -1 ];
            _array[_size - 1 ] = temp;
            _size--;
            maxHeapify(0);
            return temp;
        }

        void increaseKey(int index, int value){
            _array[index] = value;
            int indexParent = getParentIndex(index);
            while(index>0 && _array[indexParent] < _array[index]){
                int _temp = _array[indexParent];
                _array[indexParent] =  _array[index];
                _array[index] = _temp;

                index = indexParent;
                indexParent = getParentIndex(index);
            }
        }

        void insert(int value){
            increaseArraySize();
            _array[_size-1] = INT_MIN;
            increaseKey(_size-1, value);
        }

        void print(){
            for(int i = 0;i< _size;i++){
                cout << _array[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    const int array[] = {10,20,25,6,12,15,4,16};
    MaxHeap maxHeap(8, array, true);
    maxHeap.print();
    maxHeap.insert(16);
    maxHeap.print();
    return 0;
}