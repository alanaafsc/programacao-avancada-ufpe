#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


class stack
{
    int * arranjo;
    int topo;
    int tamanho;

  public:
    stack (int tamanho);
    bool stackEmpty();
    int push(int number);
    int pop();
    int printArranjo();
};

stack::stack (int tamanhoArr) {
  tamanho = tamanhoArr;
  topo = -1;
  arranjo = new int[tamanho];
};

bool stack::stackEmpty () {
  if(topo < 0) {
    return true;
  }
  return false;
};

int stack::push (int number) {
  if(topo == tamanho - 1) {
    cout << "Full stack" << endl;
    return 0;
  }

  topo = topo + 1;
  arranjo[topo] = number;
  // cout << "topo: " << topo << endl;
  // printArranjo();
  printArranjo();

  cout << number << " pushed to the stack" << endl;
  return arranjo[topo];
};

int stack::pop () {

  if(stackEmpty()) {
    cout << "Empty stack" << endl;
    return 0;
  } else {
    topo = topo - 1;
    // cout << "topo: " << topo << endl;
    // printArranjo();
    printArranjo();

    cout << arranjo[topo+1] << " popped from the stack" << endl;
    return arranjo[topo + 1];
  }
};


int stack::printArranjo () {
  for(int i = 0; i < topo + 1; i++) {
    cout << arranjo[i] << " ";
  }
  cout << endl;
};


int main()
{

  // Initialize random seed to generate random numbers
  srand (time(NULL));

  // Create a stack with 10 elements
  stack s(10);

  // Result for push and pop
  int result = 1;

  // While the stack is not full or empty
  while(result)
  {
    if ((rand() % 100) < 50)
    {
        // Push to the stack a random number between 1 and 100
        result = s.push(rand() % 100 + 1);
    }
    else
    {
        // Pop the last entry
        result = s.pop();
    }
  }

}
