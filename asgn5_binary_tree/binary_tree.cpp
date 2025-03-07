#include <iostream>
#include <string>
using namespace std;

template <class T>
class BinaryTree{
    private:
        const int PRE_ORDER_TRAVERSAL = -1;
        const int IN_ORDER_TRAVERSAL = 0;
        const int POST_ORDER_TRAVERSAL = 1;

        class Node{
          public:
            Node* left;
            Node* right;
            T value;
            Node(const T& val){
              left=right=nullptr;
              value = val;
            }  
        };

        Node *_root;

        void insert(Node *&root, string preOrder, string inOrder){
          Node *node = new Node(preOrder[0]);
          root = node;
          if(preOrder.length()<=1){
            return;
          }
          string inOrderLeft = inOrder.substr(0, inOrder.find(preOrder[0]));
          string inOrderRight = inOrder.substr(inOrder.find(preOrder[0])+1);
     
          string preOrderLeft = preOrder.substr(1, inOrderLeft.length());
          string preOrderRight = preOrder.substr(inOrderLeft.length()+1);
          
          insert(node->left, preOrderLeft, inOrderLeft);
          insert(node->right, preOrderRight, inOrderRight);

        }

        void deleteTree(Node *root){
          if(!root){
            return;
          }
          deleteTree(root->left);
          deleteTree(root->right);
          delete root;
        }
        void travel(Node *node, int _travelId) const{
          if(!node){
            return;
          }
          if(_travelId == PRE_ORDER_TRAVERSAL){
            cout << node->value;
          }
          travel(node->left, _travelId);
          if(_travelId == IN_ORDER_TRAVERSAL){
            cout << node->value;
          }
          travel(node->right, _travelId);
          if(_travelId == POST_ORDER_TRAVERSAL){
            cout << node->value;
          }
        }
     
    public:
        BinaryTree(string preOrder, string inOrder){
          if(preOrder.length()!=inOrder.length()){
            throw runtime_error("Length mismatch");
          }
          _root = nullptr;
          insert(_root, preOrder,  inOrder);
        }

        ~BinaryTree(){
          deleteTree(_root);
        }

        void preOrderTravel() const{
          travel(_root, PRE_ORDER_TRAVERSAL);
          cout << endl;
        }

        void inOrderTravel() const{
          travel(_root, IN_ORDER_TRAVERSAL);
          cout << endl;
        }
  
        void postOrderTravel() const{
          travel(_root, POST_ORDER_TRAVERSAL);
          cout << endl;
        }
  
        

        void printTree(Node* node, string prefix = "", bool isLeft = true) const {
          if (node == nullptr) return;
  
          cout << prefix;
          cout << (isLeft ? "├── " : "└── ");
          cout << node->value << endl;
  
          string newPrefix = prefix + (isLeft ? "│   " : "    ");
          printTree(node->left, newPrefix, true);
          printTree(node->right, newPrefix, false);
      }
  
      void showTree() {
          printTree(_root, "", false);
      }

};

int main(){
  // string preOrder = "ABECFJG";
  // string inOrder = "BEAJFCG";
  string preOrder = "ABDECFG";
  string inOrder = "DBEAFCG";
  BinaryTree<char> bt(preOrder, inOrder);
  bt.showTree();
  cout << endl;
  bt.preOrderTravel();
  bt.inOrderTravel();
  bt.postOrderTravel();
  return 0;
}