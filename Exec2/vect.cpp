#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct vect{
  string name;
  int nbElement;
  float* p_vector;
};

void setVectorName(vect &vetor, string name) {
  vetor.name = name;
};

void setVectorDimension (vect &vetor) {
  cout << "Qual será o comprimento do vetor? ";
  cin >> vetor.nbElement;
  cout << "Comprimento será: " << vetor.nbElement << endl;
  
};

void allocateVectorMemory(vect &vetor) { 
  vetor.p_vector = new float[vetor.nbElement];
};

void assignVectorValues(vect &vetor){
  for(int i = 0; i < vetor.nbElement; i++) {
    cout << "Insira o valor de posição " << i + 1 << " do vetor: ";
    cin >> vetor.p_vector[i];
  }
};

void printVector(vect &vetor) {
  cout << "Nome do vetor: " << vetor.name << endl;
  cout << "Valores do vetor: ";
  for(int i = 0; i < vetor.nbElement; i++) {
    cout << vetor.p_vector[i] << " ";
  }
  cout << endl;
};


void vectorialProduct(vect &vetorA, vect &vetorB) {
  float vetorResultado[vetorB.nbElement];
  float produtoEscalar = 0;
  if (vetorA.nbElement < 4 && vetorB.nbElement < 4) {
    float i = vetorA.p_vector[1] * vetorB.p_vector[2] - vetorA.p_vector[2] * vetorB.p_vector[1];
    float j = vetorA.p_vector[2] * vetorB.p_vector[0] - vetorA.p_vector[0] * vetorB.p_vector[2];
    float k = vetorA.p_vector[0] * vetorB.p_vector[1] - vetorA.p_vector[1] * vetorB.p_vector[0];
    vetorResultado[0] = i;
    vetorResultado[1] = j;
    vetorResultado[2] = k;
    cout << "Resultado do produto vetorial é: ";
    for(int i = 0; i < vetorA.nbElement; i++) {
      cout << vetorResultado[i] << " ";
    }
    cout << endl;

  } else {
    //produto escalar caso vetor tenha mais de 3D
    for(int i = 0; i < vetorA.nbElement; i++) {
      produtoEscalar += (vetorA.p_vector[i] * vetorB.p_vector[i]);
    }
    cout << "Resultado do produto escalar é: " << produtoEscalar << endl;
  } 
};

int main ()
{
  // Declare 2 vectors;
  vect A;
  vect B;

  // Initialize vector A
  setVectorName(A, "A");
  setVectorDimension(A);
  allocateVectorMemory(A);
  assignVectorValues(A);
  printVector(A);

  // Initialize vector B
  setVectorName(B, "B");
  setVectorDimension(B);
  allocateVectorMemory(B);
  assignVectorValues(B);
  printVector(B);
  
  // Compute A*B
  vectorialProduct(A,B);
 // float result = vectorialProduct(A,B);
  //cout << A.name << "*" << B.name << " = " << result << endl;
  return 0;
}
