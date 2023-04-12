#include <iostream>

using namespace std;

// Função para mesclar dois arranjos classificados
void merge(int A[], int B[], int m, int n) {
    int i = m - 1; // índice do último elemento em A
    int j = n - 1; // índice do último elemento em B
    int k = m + n - 1; // índice do último elemento em A após a mesclagem

    while (i >= 0 && j >= 0) { // enquanto ainda houver elementos em A e B
        if (A[i] > B[j]) { // o elemento em A é maior que o elemento em B
            A[k--] = A[i--]; // insere o elemento de A em A[k] e decrementa i e k
        } else { // o elemento em B é maior que o elemento em A
            A[k--] = B[j--]; // insere o elemento de B em A[k] e decrementa j e k
        }
    }

    // Insere os elementos restantes de B em A 
    while (j >= 0) {
        A[k--] = B[j--];
    }
}

int main() {
    int A[10] = {1, 3, 5, 7, 9}; 
    int B[] = {2, 4, 6, 8, 10}; 
    int m = 5; // dimensão de A
    int n = 5; // dimensão de B
    
    merge(A, B, m, n);

    for (int i = 0; i < m + n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
