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
            if(head->val==val){
                Node *tempHead = head;
                head = head->node;
                delete tempHead;
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

        int length() const{
            if(head==tail && head==nullptr){
                return 0;
            }
            int counter = 1;
            Node *temp = head;
            while(temp->node){
                counter++;
                temp = temp->node;
            }

            return counter;
        }

        // T& removeFirst(){
        //     int length = this->length();
        //     if(length==0){
        //         throw std::runtime_error("Tried to remove from an empty array");
        //     }
        //     if(length==1){
        //         T &val = head->val;
        //         head = nullptr;
        //         tail = nullptr;
        //         return val;
        //     }

        //     Node *temp = head;
        //     T &val = head->val;
        //     head = head->node;
        //     delete temp;
        //     return val;
        // }
        T removeFirst(){
            int length = this->length();
            if(length==0){
                throw std::runtime_error("Tried to remove from an empty array");
            }
            if(length==1){
                T &val = head->val;
                head = nullptr;
                tail = nullptr;
                return val;
            }

            Node *temp = head;
            T val = head->val;
            head = head->node;
            delete temp;
            return val;
        }

        T removeLast(){
            int length = this->length();
            if(length==0){
                throw std::runtime_error("Tried to remove from an empty array");
            }
            if(length==1){
                T &val = head->val;
                head = nullptr;
                tail = nullptr;
                return val;
            }

            Node *temp = head;
            while(temp->node!=tail){
                temp = temp->node;
            }
            T val = tail->val;
            delete tail;
            tail = temp;
            
            tail->node = nullptr;
            return val;
        }
};




int main(){
    LinkedList<int> linkedList;
    linkedList.print();
    
    linkedList.append(1);
    linkedList.print();

    cout << "First element " << linkedList.removeFirst() << endl;
    linkedList.print();


    linkedList.append(2);
    linkedList.append(3);

    linkedList.print();

    cout << "First element " << linkedList.removeFirst() << endl;
    linkedList.print();

    linkedList.append(5);
    linkedList.append(4);
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(0);
    linkedList.print();

    cout << "Last element " << linkedList.removeLast() << endl;
    linkedList.print();

    cout << "Last element " << linkedList.removeLast() << endl;
    linkedList.print();
    cout << "Last element " << linkedList.removeLast() << endl;
    linkedList.print();
    cout << "Last element " << linkedList.removeLast() << endl;
    linkedList.print();
    cout << "Last element " << linkedList.removeLast() << endl;
    linkedList.print();
    cout << "Last element " << linkedList.removeLast() << endl;
    linkedList.print();
   
    return 1;
}