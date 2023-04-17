#include <iostream>

using namespace std;

void merge(int A[], int B[], int m, int n) {
    int i = m - 1; // índice do último elemento em A
    int j = n - 1; // índice do último elemento em B
    int k = m + n - 1; // índice do último elemento em A após mesclagem

    while (i >= 0 && j >= 0) { 
        if (A[i] > B[j]) { 
            A[k--] = A[i--]; 
        } else { 
            A[k--] = B[j--]; 
        }
    }

    //Insere os elementos restantes de B em A 
    while (j >= 0) {
        A[k--] = B[j--];
    }
}

int main() {
    int A[10] = {1, 3, 5, 7, 9}; 
    int B[] = {2, 4, 6, 8, 10}; 
    int m = 5; 
    int n = 5; 
    
    merge(A, B, m, n);

    for (int i = 0; i < m + n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
