#include <iostream>
using namespace std;

void bubbleSort(int * A, int size) {
  int number;
  int idx = 0;
  bool troc = true;
  int i = 0;
  while (i != size - 2 && troc) {
    troc = false;
    for(int j = 1; j < size - idx; j++) {
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

void printArray(int * A, int size){
  for (int i = 0; i < size; i++) {
    cout << A[i]  << " ";
  }
  cout << endl;
};

int main () {
  int t[] = {31, 9, 4, 7, 3, 18, 23, 54, 99, 87, 54, 35, 90, 1, 22, 30, 49, 77, 5, 76};
  int *ptr_t = t;
  int size = sizeof(t) / sizeof(t[0]);

  printArray(ptr_t, size);
  bubbleSort(ptr_t, size);

  //Ordenando
  cout << "Array ordenado: " << endl;
  printArray(ptr_t, size);

  return 0;
};
