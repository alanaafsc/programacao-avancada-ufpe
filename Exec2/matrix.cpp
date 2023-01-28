#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct matrix{
  string name;
  int nbCol;
  int nbLin;
  float** p_matrix;
};

void setMatrixName(matrix &m, string name) {
  m.name = name;
};

void setMatrixDimensions (matrix &m) {
  cout << "Qual será o número de colunas da matriz? ";
  cin >> m.nbCol;
  cout << "e o número de linhas? ";
  cin >> m.nbLin;
  cout << "Número de colunas e linhas: " << m.nbCol << " x " << m.nbLin << endl;
};

void allocateMatrixMemory(matrix &m) { 
  m.p_matrix = new float*[m.nbLin];
  for(int i = 0; i < m.nbLin; i++){
    m.p_matrix[i] = new float[m.nbCol];
  }
};

void assignMatrixValues(matrix &m) {
  for(int i = 0; i < m.nbLin; i++) {
    for(int j = 0; j<m.nbCol; j++) {
      cout << "Insira o valor de posição [" << i + 1 << "][" << j + 1 << "] da matriz: ";
      cin >> m.p_matrix[i][j];
    }
  }
}

void printMatrix(matrix &m) {
  cout << "Nome da matriz: " << m.name << endl;
  cout << "Valores da matriz: " << endl;
  for(int i = 0; i < m.nbLin; i++) {
    for(int j = 0; j<m.nbCol; j++) { 
      cout << m.p_matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void multiplyMatrices(matrix &A, matrix &B, matrix &C) {
  // Compute C = A*B
  // multiplicacao só é possivel se num. de colunas de A = num. de linhas de B
  if(A.nbCol != B.nbLin){
    cout << "Não é possível efetuar a multiplicação" << endl;
  } else{
    C.nbLin=A.nbLin;
    C.nbCol=B.nbCol;
    allocateMatrixMemory(C);
    int somaprod;
    for(int i = 0; i < A.nbLin; i ++) {
      for(int j = 0; j < B.nbCol; j ++) {
        for(int k = 0; k < A.nbCol; k++) {
          somaprod = A.p_matrix[i][k]*B.p_matrix[k][j];
          C.p_matrix[i][j] += somaprod;
        }
      }
    }
  }
};


int main ()
{
  // Declare 3 matrices
  matrix A;
  matrix B;
  matrix C;

  // Initialize matrix A
  setMatrixName(A, "A");
  setMatrixDimensions(A);
  allocateMatrixMemory(A);
  assignMatrixValues(A);
  printMatrix(A);

  // Initialize matrix B
  setMatrixName(B, "B");
  setMatrixDimensions(B);
  allocateMatrixMemory(B);
  assignMatrixValues(B);
  printMatrix(B);

  // Compute C = A*B
  setMatrixName(C, "C");
  multiplyMatrices(A,B,C);
  printMatrix(C);
  return 0;
}