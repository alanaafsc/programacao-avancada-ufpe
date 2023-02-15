#include <iostream>
using namespace std;

class Node {
public:
  int data[2];
  Node* next;
  Node(int x1, int x2) {
    data[0] = x1;
    data[1] = x2;
  }
};

class List {
public:
  Node * head = NULL;
  // void buildList() {

//  }


};

int main (){
  Node node(1,2);
  cout << node.data[0] << node.data[1];
  List list;
  return 0;
};
