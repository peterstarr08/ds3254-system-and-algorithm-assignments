#include <iostream>
using namespace std;

template <class T>
class LinkedList{
    private:
        class Node{
            public:
                Node *node;
                T val;
                Node(const T &value){
                    val  = value;
                    node = nullptr;
                }
        };
        Node *head;
        Node *tail;
    public:  
        LinkedList(){
            head = tail = nullptr;
        }
        ~LinkedList(){
            Node *tempHead = nullptr;
            while(head){
                tempHead = head;
                head = head->node;
                delete tempHead;
            }
        }

        void append(const T &val){
            Node *node = new Node(val);
            if(head==nullptr){
                head = tail = node;
            }
            else{
                tail->node = node;
                tail = node;
            }
        }

        void prepend(const T &val){
            Node *node = new Node(val); //Why was new used in lecture slides?
            if(head==nullptr){
                head = tail = node;
            }
            else{
                node->node = head;
                head = node;
            }
        }

        void remove(const T& val){
            if(head==nullptr){
                return;
            }
            if(head==tail && head->val==val){
                head = tail = nullptr;
                return;
            }
            Node *temp = head;
            while((temp->node) && (temp->node)->val!=val){
                temp = temp->node;
            }

            if(temp->node){ //if the element was found, it is guaranteed the pointer did not reach the very last element, so exploiting that
                if(!(temp->node->node)){ //temp is the second last node
                    Node *temp2 = temp->node;
                    tail = temp;
                    tail->node = nullptr;
                    delete temp2;
                    return;
                }
                Node *chain = temp->node;
                temp->node = chain->node;
                delete chain;
            }

        }

        void print() const {
            if(!head){
                cout << "Empty Linked List" <<endl;
                return;
            }
            Node *temp = head;
            do{
                cout << temp->val << "-->";
                temp = temp ->node;
            }while(temp);
            cout << "null"<<endl;
            delete temp;

        }

};

int main(){
    LinkedList<int> linkedList;
    linkedList.print();
    linkedList.append(55);
    linkedList.print();
    linkedList.prepend(66);
    linkedList.print();
    linkedList.append(3);
    linkedList.print();
    linkedList.append(0);
    linkedList.print();
    linkedList.prepend(999);
    linkedList.print();
    linkedList.remove(0);
    linkedList.print();
    return 1;
}