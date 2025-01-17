#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int getMin(int a[], int i, int j) {
  int min = i;
  for(int k = i + 1; k <= j; k++) {
    if (a[k] < a[min]) {
      min = k;
    }
  }
  return min;
}

//Selection sort
void sort(int x[], int size){
    for(int i = 0;i<size;i++){
        int minIndex = getMin(x, i, size-1);
        int temp = x[i];
        x[i] = x[minIndex];
        x[minIndex] = temp;
    }
}

int main() {

  ofstream dataFile("asgn2_sorting_algorith_analysis/selection_sort_data.txt", ofstream::trunc);
  if (!dataFile) {
      cerr << "Error opening file for writing." << std::endl;
      return 1;
  }
  
  dataFile << "size,time\n";

  for(int k = 1;k<=1000;k++){

    //Make sure files are generated using the data generation code
    ifstream sampleFile("asgn2_sorting_algorith_analysis/data/samples/file"+to_string(k)+".txt");

    if (!sampleFile.is_open()) {
        cout << "File not found!" << endl;
        return 1;
    }

    cout << "Reading file: " << "file"+to_string(k)+".txt" << '\n';

    int elementData;
    int counter = 0;

    vector<int> data;

    while(sampleFile>>elementData){
      counter++;
      data.push_back(elementData);
    }
    
    cout << "Total values read: " << counter << '\n';

    int arr[data.size()];

    for(int i = 0; i < data.size(); i++){
        arr[i] = data[i];
    }

    auto start = chrono::high_resolution_clock::now();
    sort(arr, counter);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    dataFile << counter << "," << duration.count() << "\n";


    cout << "\nTime taken to sort the array: " << duration.count() << " seconds" << "\n\n";
    sampleFile.close(); 
  }
  dataFile.close();
  return 0;
}