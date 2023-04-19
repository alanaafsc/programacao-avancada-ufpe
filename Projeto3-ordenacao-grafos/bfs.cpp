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
}

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

  for(int i = 0; i < nbNodes; i++) {
    nodeList[i].color = 0;
    nodeList[i].distance = numeric_limits<int>::max();
    nodeList[i].previous = -1;
  }
  nodeList[source].color = 1;
  nodeList[source].distance = 0;
  nodeList[source].previous = -1;

  Queue * Q = new Queue(); // Conjunto de vértices cinzentos
  Q->enQueue(source); // Source entrará como data no QNode

  while(Q->front != NULL) {
    int u = Q->front->data;
    Q->deQueue();
    for(int i = 0; i < nbNodes; i++) {
      if(table[u][i] != 0 && nodeList[i].color == 0) {
        nodeList[i].color = 1;
        nodeList[i].distance = nodeList[u].distance + 1;
        nodeList[i].previous = u;
        Q->enQueue(i);
      }
    }
    nodeList[u].color = 2;
  }
};

void graph::printPath(int source, int destination) {
  // cria um vetor para armazenar o caminho percorrido durante a busca em largura
  int * path = new int[nbNodes];

  if (destination == source) {
    cout << "Path from " << source << " to node " << destination << endl;
    cout << source << " ";
  } else if (nodeList[destination].previous == -1) {
    cout << "No path found from " << source << " to node " << destination << endl;
  } else {
    int index = 0;
    int current = destination;

    // percorre o caminho percorrido a partir do nó de destino e armazena em um vetor
    while (current != source) {
      if (nodeList[current].previous != -1) {
        path[index++] = current;
      }
      current = nodeList[current].previous;
    }

    path[index] = source;

    // ordem inversa
    cout << "Path from " << source << " to node " << destination << endl;
    for (int i = index; i >= 0; i--) {
      if (path[i] != -1) {
        cout << path[i] << " ";
      }
    }
    cout << endl;
  }

  // Libera memória:
  delete[] path;
};

int main()
{
  // Create a graph
  graph g("graph1.txt",9);

  // Call Breadth-first search from node 0
  g.bfs(0);

  // Print path to from 0 to 4
  g.printPath(0,4);

  return 0;
}
