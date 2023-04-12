#include <iostream>
#include <limits>
using namespace std;

//A - arranjo
//p, q, r -indices de enumeracao dos elementos do arranjo (p<= q < r)

void printArray(int * A, int size){
  for (int i = 0; i < size; i++) {
    cout << A[i]  << " ";
  }
  cout << endl;
};

void merge(int * A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q ;
  int * newArray1 = new int[n1+1];
  int * newArray2 = new int[n2+1];

  for(int i = 0; i < n1; i++) {
    newArray1[i] = A[p + i];
  }

  for(int j = 0; j < n2; j++) {
    newArray2[j] = A[q + j + 1];
  }

  newArray1[n1] = numeric_limits<int>::max();
  newArray2[n2] = numeric_limits<int>::max();

  int i = 0;
  int j = 0;

  for(int k = p; k <= r; k++) {
    if(newArray1[i] <= newArray2[j]) {
      A[k] = newArray1[i];
      i = i + 1;
    } else {
      A[k] = newArray2[j];
      j = j + 1;
    }
  }
};

void mergeSort (int * A, int p, int r) {
  if(p < r) {
    int q = (p+r)/2;
    mergeSort(A, p, q);
    mergeSort(A, q+1, r);
    merge(A, p, q, r);
  }
};


int main () {

  int t[] = {31, 9, 4, 7, 3, 18, 23, 54, 99, 87, 54, 35, 90, 1, 22, 30, 49, 77, 5, 76};
  int size = sizeof(t) / sizeof(t[0]);

  mergeSort(t, 0, size-1);
  printArray(t, size);

  return 0;
}