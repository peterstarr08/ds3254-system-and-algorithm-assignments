#include <iostream>
using namespace std;

int main(int argc, char** args){
    cout << argc << endl;
    for(int  i = 0;i <argc ;i++){
        cout << args[i] << endl;
    }
    return 0;
}