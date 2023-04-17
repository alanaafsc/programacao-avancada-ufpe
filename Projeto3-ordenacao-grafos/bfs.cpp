#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

struct GNode
{
  int color; // 0 white 1 grey 2 black
  int distance;
  int previous;
};

// FILA:
// class QNode {
// public:
//   int data;
//   QNode* next;
//   QNode (int number) {
//     data = number;
//     next = NULL;
//   };
// };

class Queue {
public:
    GNode *front, *rear;
    Queue ();
    void enQueue(GNode node);
    GNode deQueue();
    void printQueue();
};

Queue::Queue () {
  front = NULL;
  rear = NULL;
}

void Queue::enQueue(GNode * node) {
  // GNode *node = new GNode();
  if(rear == NULL) {
    rear = node;
    front = node;
  }
  else{
  rear->previous = node;
  rear = node;
  }
  // cout << "Enqueue " << node->distance << endl;
  printQueue();
};

GNode Queue::deQueue () {
  if(front != NULL) {
    GNode * node = front;
    cout << "Dequeue " << front->distance << endl;

    front = front->previous;
    delete node;
  }

  // if(front == NULL) {
  //   cout << "Empty queue" << endl;
  // }

  printQueue();
};

void Queue::printQueue() {

  if(front != NULL) {
    QNode * node;
    node = front;
    cout << "Fila " ;
    while(node != NULL) {
      cout << node->data << " ";
      node = node->next;
    }
    cout << endl;
  }
};

// =========================================================

// Graph node

class graph
{
public:
  int nbNodes;
  int** table;
  GNode* nodeList;

  // Create graph from a file, with a given number of nodes
  graph(string, int);

  // Breadth-first search algorithm from a given node
  void bfs(int);

  // Print the path from the source to a given node
  void printPath(int, int);
};

graph::graph (string file, int nodes) {
  nbNodes = nodes;
  table = new int*[nbNodes];
  for(int i = 0; i < nodes; i++) {
    table[i] = new int[nbNodes];
  }

  ifstream fileStream;
  fileStream.open(file);
  string line;
  if(fileStream.is_open()) {
    for(int i = 0; i < nbNodes; i++) {
      for(int j = 0; j < nbNodes; j++) {
            fileStream >> table[i][j];
          }
        }
    }

  fileStream.close();

  for(int i = 0; i < nbNodes; i++) {
    for(int j = 0; j < nbNodes; j++) {
      cout << table[i][j] << " ";
    }
    cout << endl;
  }

  nodeList = new GNode[nbNodes];

};


void graph::bfs(int source) {
  for(GNode node : nodeList) {
    node->color = 0;
    node->distance = numeric_limits<int>::max();
    node->previous = NULL;
  }
  GNode * source = new GNode();
  source->color = 1;
  source->distance = 0;
  source->previous = NULL;

  Queue * Q = new Queue();
  enQueue(source);

  while(Q != NULL) {
    GNode u = deQueue();
  }

}




int main()
{
  // Create a graph
  graph g("graph1.txt",9);

  // Call Breadth-first search from node 0
  g.bfs(0);

  // Print path to from 0 to 4
  // g.printPath(0,4);

  return 0;
}
