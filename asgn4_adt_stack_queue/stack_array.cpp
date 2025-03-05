#include <iostream>
using namespace std;

template <class T>
class Stack{
    private:
        T* _stack;
        int _capacity;
        int _top; //simply points to the index of top most element

        const int EMPTY_STACK = -1;
    public:
        Stack(const int capacity){
            _capacity = capacity;
            _top = EMPTY_STACK;
            _stack = new T[_capacity];
        }
        ~Stack(){
            delete[] _stack;
        }
        int size(){
            return _top+1;
        }
        int capacity(){
            return _capacity;
        }
        void push(const T val){
            if(is_full()){
                throw runtime_error("Stack Overflow!");
            }
            _stack[++_top] = val;
        }
        bool is_empty(){
            return _top==EMPTY_STACK;
        }
        bool is_full(){
            return _top>=_capacity-1;
        }
        T top(){
            if(is_empty()){
                throw runtime_error("Stack is empty!");
            }
            return _stack[_top];
        }
        T pop(){
            if(is_empty()){
                throw runtime_error("Stack is empty!");
            }
            return _stack[_top--];
        }
        void display() {
            if (is_empty()) {
                cout << "Stack is empty!" << endl;
                return;
            }
            cout << "Top" << endl;
            for (int i = _top; i >= 0; i--) {
                cout << _stack[i] << endl;
            }
            cout << "Bottom" << endl;
        }
};

int main() {

    Stack<int> stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    cout << "Stack contents:" << endl;
    stack.display();

    cout << "\nTop element: " << stack.top() << endl;

    cout << "\nPopping element: " << stack.pop() << endl;
    cout << "\nStack after popping:" << endl;
    stack.display();

    stack.push(50);
    cout << "\nStack after pushing 50:" << endl;
    stack.display();


    return 0;
}