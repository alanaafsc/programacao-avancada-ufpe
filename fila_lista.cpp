#include <iostream>
using namespace std;

class QNode {
public:
  int data;
  Node* next;

};

class Queue {
public:
    QNode *front, *rear;
    void enQueue(int number);
    void deQueue();
};


Queue::Queue () {
  front->next = NULL;
  rear->next = NULL;
};

void Queue::enQueue(int number)
//  QNode(
  if(front == NULL) {
    front->data = number;
    front->next = NULL;
  }
  rear->data = number;
  rear->next = NULL;


}


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
