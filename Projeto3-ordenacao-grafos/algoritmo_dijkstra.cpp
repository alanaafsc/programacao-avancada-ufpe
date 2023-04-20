
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

// Codigo de Fila Lista:
class QNode {
public:
  int data;
  QNode* next;
  QNode (int number) {
    data = number;
    next = NULL;
  };
};

class Queue {
public:
    QNode *front, *rear;
    Queue ();
    void enQueue(int number);
    void deQueue();
    void printQueue();
};

Queue::Queue () {
  front = NULL;
  rear = NULL;
};

void Queue::enQueue(int number) {
  QNode *node = new QNode(number);
  if (front == NULL) {
    rear = node;
    front = node;
  }
  else {
    rear->next = node;
    rear = node;
  }
  cout << "Enqueue " << number << endl;
  printQueue();
};

void Queue::deQueue () {
  if(front != NULL) {
    QNode * node = front;
    cout << "Dequeue " << front->data << endl;
    front = front->next;
    delete node;
  }

  if(front == NULL) {
    cout << "Empty queue" << endl;
  }

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

struct GNode
{
  int color; // 0 white 1 grey 2 black
  int distance;
  int previous;
};

class graph
{
public:
  int nbNodes; // n de nodes
  int** table; // importar graph em table
  GNode* nodeList; // lista de nodes

  // Create graph from a file, with a given number of nodes
  graph(string, int);

  // Breadth-first search algorithm from a given node
  void dijkstra(int);

  // Print the path from the source to a given node
  void printPath(int, int);

  void relax(int i, int j);
  int extractMin(Queue *Q);
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

void graph::relax(int i, int j) {
  if(nodeList[j].distance > (nodeList[i].distance + table[i][j])) {
    nodeList[j].distance = nodeList[i].distance + table[i][j];
    nodeList[j].previous = i;
  }
};

int graph::extractMin(Queue *Q) {
  int min = numeric_limits<int>::max();
  int minIndex = -1;
  QNode *current = Q->front;
  while(current != NULL) {
    int index = current->data;
    if(nodeList[index].distance < min) {
      min = nodeList[index].distance;
      minIndex = index;
    }
    current = current->next;
  }
  return minIndex;
}

void graph::dijkstra(int source) {

  for(int i = 0; i < nbNodes; i++) {
    nodeList[i].color = 0;
    nodeList[i].distance = numeric_limits<int>::max();
    nodeList[i].previous = -1;
  }
  nodeList[source].color = 1;
  nodeList[source].distance = 0;
  nodeList[source].previous = -1;

  Queue * Q = new Queue(); // Conjunto de vértices pretos
  Q->enQueue(source); // Source entrará como data no QNode

  while(Q->front != NULL) {
    int u = extractMin(Q);
    Q->deQueue();
    for(int i = 0; i < nbNodes; i++) {
      if(table[u][i] != 0 && nodeList[i].color == 0) {
        relax(u, i);
        nodeList[i].color = 1;
        Q->enQueue(i);
      }
    }
    nodeList[u].color = 2;
  }
};

void graph::printPath(int source, int destination) {
  if(destination == source) {
    cout << source << " ";
  }
  else if(nodeList[destination].previous == -1) {
    cout << "No path from " << source << " to " << destination << " exists" << endl;
  }
  else {
    printPath(source, nodeList[destination].previous);
    cout << destination << " ";
  }
};


int main()
{
  // Create a graph
  graph g("graph2.txt",5);

  // Call Dijkstra algorithm from node 0
  g.dijkstra(0);

  // Print path to from 0 to 2
  cout << "Path from 0 to node 2" << endl;
  g.printPath(0,2);

  return 0;
}
