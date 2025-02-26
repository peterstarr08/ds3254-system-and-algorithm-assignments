#include <iostream>
using namespace std;

template <class T>
class Queue{
    private:
        class Node{
            public:
            Node *prev;
            Node *next;
            T value;
            Node(const T& value){
                prev = next = nullptr;
                this->value = value;
            }
        };

        Node *first;
        Node *last;
        int size;
    public:
        Queue(){
            first=last=nullptr;
            size = 0;
        }
        ~Queue(){
            Node *_temp = nullptr;
            while(first){
                _temp = first;
                first = first->next;
                delete _temp;
            }
        }
        
        void enqueue(const T& val){
            Node *element = new Node(val);
            if(!first){ 
                first=last=element;
            }
            else{
                last->next = element;
                element->prev = last;

                last = element;
            }
            size++;
        }

        T getFirst(){
            if(!first){
                throw std::runtime_error("Empty queue");
            }
            return first->value;
        }

        T deque(){
            if(!first){
                throw std::runtime_error("Empty queue");
            }

            T value = first->value;
            Node *_first = first;

            if(first==last){
                first=last=nullptr;
            }
            else{
                first = first->next;
            }

            delete _first;
            size--;
            return value;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size==0;
        }

        void print(){
            cout << "Size: "<< size << '\n';
            cout << "First [ ";
            Node *_first = first;
            while(_first){
                cout << '\t' << _first->value;
                _first = _first ->next;
            }
            cout << " ] Last" <<endl;
        }
};

int main(){
    Queue<int> queue;
    queue.print();

    queue.enqueue(5);
    queue.print();

    queue.enqueue(9);
    queue.enqueue(7);
    queue.print();

    cout << queue.getFirst() << '\n';

   // cout << queue.deque() << '\n';
    queue.deque();
    queue.print();
    queue.deque();
    queue.print();
    queue.deque();
    queue.print();

    //queue.deque();
    return 1;
}