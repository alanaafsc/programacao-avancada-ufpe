#include <iostream>
using namespace std;

void bubbleSort(int* A) {
  int size = sizeof(A)/sizeof(int);
  cout << size << endl;
  int number;
  int idx = 0
  bool troc;
  int i = 0;
  while (i != size - 1 && troc) {
    troc = false;
    for(int j = 1; j < size - idx; j++)
    {
      if(A[j] < A[j - 1]) {
        troc = true;
        number = A[j];
        A[j] = A[j - 1];
        A[j - 1] = number;
      }

    }
    idx++;
    i++;
  }
};

void printArray(int * A){
  int size = sizeof(A)/sizeof(int);
  for (int i = 0; i < size; i++) {
    cout << A[i]  << " ";
  }
  cout << endl;
};

int main () {
  int * t;
  int t[] = {1, 30, 4, 3, 2, 10};

  bubbleSort(t);
  printArray(t);
  return 0;
}
