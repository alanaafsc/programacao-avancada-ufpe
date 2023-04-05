#include <iostream>
using namespace std;
//r - comprimento - 1
//p - primeiro elemento (indice 0)
//q - pivo

void printArray(int * A, int size);

int partition(int* A, int p, int r) {
  int x = A[r]; //pivô inicial
  int i = p - 1;
  int temp;
  for(int j = p; j < r; j++) {
    if(A[j] <= x) {
      i = i + 1;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
    printArray(A, r);
  }
  temp = A[i+1];
  A[i + 1] = A[r];
  A[r] = temp;
  return i + 1;
};


void printArray(int * A, int size){
  for (int i = 0; i <= size; i++) {
    cout << A[i]  << " ";
  }
  cout << endl;
};

void quickSort(int* A, int p, int r) {
  int q;
  if(p < r) {
    q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q + 1, r);
  }
  // printArray(A, r);
};


int main () {

  int t[] = {31, 9, 4, 7, 3, 18, 23, 54, 99, 87, 54, 35, 90, 1, 22, 30, 49, 77, 5, 76};
  int size = sizeof(t) / sizeof(t[0]);

  quickSort(t, 0, size-1);
  cout << "Array ordenado: ";
  printArray(t, size-1);

  return 0;
}
