#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <algorithm>
#include <random>
#include <cstdlib>  // for rand() and srand()
// #include <ctime> 
#include <bits/stdc++.h>

using namespace std;

const int iterations = 3;


int getMin(int a[], int i, int j) {
  int min = i;
  for(int k = i + 1; k <= j; k++) {
    if (a[k] < a[min]) {
      min = k;
    }
  }
  return min;
}

double getMean(double a[], int size){
    double sum = 0;
    for(int i = 0;i<size;i++){
        sum += a[i];
    }
    return sum/size;

}


void shuffler(int a[], int size){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
    shuffle(a, a + size, default_random_engine(seed));

     // Seed the random number generator
    // srand(time(0));

    // // Fisher-Yates shuffle algorithm
    // for (int i = n - 1; i > 0; --i) {
    //     // Generate a random index in range [0, i]
    //     int j = rand() % (i + 1);

    //     // Swap elements at indices i and j
    //     swap(a[i], a[j]);
    // }

}

//Selection sort
void SelectionSort(int x[], int size){
    for(int i = 0;i<size;i++){
        int minIndex = getMin(x, i, size-1);
        int temp = x[i];
        x[i] = x[minIndex];
        x[minIndex] = temp;
    }
}

//Insertion sort
void InsertionSort(int x[], int size){
    for(int i = 1;i<size;i++){
      int key = x[i];
      int j = i-1;
      while(j >= 0 && x[j] > key){
        x[j+1] = x[j];
        j = j-1;
      }
      x[j+1] = key;
    }
}

//Mergin code
void Merge(int a[], int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;
  int left[n1];
  int right[n2];

  for(int i = 0;i<n1;i++) {
      left[i] = a[p+i];
  }
  for(int i = 0;i<n2;i++){
      right[i] = a[q+i+1];
  }

  int i = 0;
  int j = 0;

  for(int k = p; k<=r;k++){
    if(j>=n2 || (i<n1 && left[i]<=right[j])){
      a[k] = left[i];
      i = i + 1;
    }
    else{
      a[k] = right[j];
      j = j + 1;
    }
  }
}

void MergeSort(int a[], int p, int r){
    if(p>=r){
        return;
    }
    int q = (p  + r)/2;
    MergeSort(a, p, q);
    MergeSort(a, q + 1, r);
    Merge(a, p, q, r);
}


int main() {

  ofstream dataFile("asgn2_sorting_algorith_analysis/sort_data.txt", ofstream::trunc);
  if (!dataFile) {
      cerr << "Error opening file for writing." << std::endl;
      return 1;
  }
  
  dataFile << "size,time_selection_sort,time_insert_sort,time_merge_sort\n";

  ifstream sampleFile("asgn2_sorting_algorith_analysis/data/random_arrays.txt");
  if (!sampleFile.is_open()) {
      cout << "File not found!" << endl;
      return 1;
  }
  
  string array;
  int counter = 1;
  
  double timeSelectionSort[iterations];
  double timeInsertionSort[iterations];
  double timeMergeSort[iterations];
  auto analysisStart = chrono::high_resolution_clock::now();
  
  while(getline(sampleFile, array, '\n')){  
    stringstream ss(array);
    int a[counter];

    for(int i = 0; i < counter; i++){
        ss >> a[i];
    }

    for(int i=0;i<iterations;i++){

      auto start = chrono::high_resolution_clock::now();
      SelectionSort(a, counter);
      auto end = chrono::high_resolution_clock::now();
      chrono::duration<double> duration = end - start;


      timeSelectionSort[i] = duration.count();

      shuffler(a, counter);

      start = chrono::high_resolution_clock::now();
      InsertionSort(a, counter);
      end = chrono::high_resolution_clock::now();
      duration = end - start;


      timeInsertionSort[i] = duration.count();

      shuffler(a, counter);


      start = chrono::high_resolution_clock::now();
      MergeSort(a, 0, counter-1);
      end = chrono::high_resolution_clock::now();
      duration = end - start;


      timeMergeSort[i] = duration.count();

      shuffler(a, counter);

      auto analysisCheckpoint = chrono::high_resolution_clock::now();
      chrono::duration<double> durationAnalysis = analysisCheckpoint - analysisStart;

      cout << "\rSorted array size:" << counter << " Time elapsed " << durationAnalysis.count() << "s." << flush;
    }

    dataFile << counter << "," << getMean(timeSelectionSort, iterations) << "," << getMean(timeInsertionSort, iterations)<< "," << getMean(timeMergeSort, iterations) << "\n";


    counter++;

  }
  auto analysisEnd = chrono::high_resolution_clock::now();
  chrono::duration<double> durationAnalysisEnd = analysisEnd - analysisStart;


  sampleFile.close();
  dataFile.close();
  cout << "\r" << "                                                                      " << "\r";
  cout << "\rSuccess! Took " << durationAnalysisEnd.count()/60 << " minutes " << flush;
  return 0;
}