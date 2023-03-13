#include <iostream>
using namespace std;

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
  if(rear == NULL) {
    rear = node;
    front = node;
  }
  else{
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

int main()
{
  // Initialize random seed to generate random numbers
  srand (time(NULL));

  // Create a queue
  Queue q;

  do
  {
    if ((rand() % 100) < 50)
    {
        // Enqueue a random number between 1 and 100
        q.enQueue(rand() % 100 + 1);
    }
    else
    {
        // Dequeue the oldest entry
        q.deQueue();
    }
  }
  // While the queue is not empty
  while(q.front != NULL);
}
