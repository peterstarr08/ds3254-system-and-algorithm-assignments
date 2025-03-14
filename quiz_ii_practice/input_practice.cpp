#include <iostream>
using namespace std;

int main(){
    string input;
    char chr;
    double dbl;
    int num;
    bool boolean;

    cout << "Enter a string: ";
    getline(cin, input);
    cout << "You entered: "<<input << endl;
    

    cout << "Enter a char: ";
    cin >> chr;
    cout << "You entered: "<<chr << endl;

    cout << "Enter a double: ";
    cin >> dbl;
    cout << "You entered: "<<dbl << endl;

    cout << "Enter a number: ";
    cin >> num;
    cout << "You entered: " << num << endl;

    cout << "Enter a boolean: ";
    cin >> boolean;
    cout << "You entered: "<<boolean << endl;


    return 0;
}