#include <iostream>

using namespace std;

template <class T>
class Stack{
    private:
        class Node{
            public:
                Node *below;
                T value;

                Node(const T &val){
                    value = val;
                    below = nullptr;
                }
        };
        Node *top;
        int size;
    public:
        Stack(){
            top = nullptr;
            size = 0;
        }

        ~Stack(){
            if(!top){
                return;
            }
            
            Node *temp = nullptr;
            while(top->below){
                temp = top;
                top = top->below;
                delete temp;
            }
        }

        void push(const T& element){
            Node *node = new Node(element);
            if(top){
                node->below = top;
                top = node;
            }
            else{
                top = node;
            }
            size++;
        }

        T getTop() const{
            if(!top){
                throw std::runtime_error("Stack is empty");
            }
            return top->value;
        }

        T pop(){
            if(!top){
                throw std::runtime_error("Stack is empty");
            }

            T value = top->value;
            Node *_temp = top;

            if(size>1){
                top = top->below;
            }
            delete _temp;
            size--;

            if(size==0){
                top= nullptr;
            }

            return value;
        }


        int getSize() const{
            return size;
        }

        bool is_empty() const{
            return size==0;
        }        

        void print() const{
            if(!top){
                cout << "Empty Stack\n";
                return;
            }
            cout << "\nSize: " << size << '\n' << "Top\n";
            Node *_temp = top;
            do{
                cout << _temp->value << '\n';
                _temp = _temp->below;
            }while(_temp);
            cout << "Bottom\n" << endl;

        }

};

int main(){
    Stack<int> stack;
    stack.print();

    stack.push(3);
    stack.push(4);
    stack.push(9);

    stack.print();

    cout << stack.getTop() << endl;

    int a = stack.pop();
    stack.print();
    a = stack.pop();
    a = stack.pop();
    stack.print();

    a = stack.pop();

    
}