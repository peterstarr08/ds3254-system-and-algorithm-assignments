#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
    string fileRead = argv[1];
    string fileWrite = argv[2];

    ifstream myFile(fileRead);
    ofstream saveFile(fileWrite);

    if(!saveFile.is_open()){
        throw runtime_error("Couldn't write the file");
    }
    
    if(!myFile.is_open()){
        throw runtime_error("Couldn't read the file");
    }

    string chunk;
    while(getline(myFile, chunk)){
        saveFile << chunk <<endl;
    }
    cout << "File copied!";
    myFile.close();
    saveFile.close();
    return 0;
}