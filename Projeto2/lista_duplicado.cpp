#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node (int number) {
        data = number;
        next = NULL;
        prev = NULL;
    };
};


class List{
public:
    Node * head;
    List () {
        head = NULL;
    }
    void insertNode (int number);
    void printList ();
    void removeDuplicates();
    void removeNode(Node* node);
};

void List::insertNode(int number) {
    Node * nodeNovo = new Node(number);
  //  cout << "Número inserido: " << number << endl;
    if(head == NULL) { // Lista vazia
        head = nodeNovo;
        return;
    }
    nodeNovo->next = head;
    head->prev = nodeNovo;
    head = nodeNovo;
};

void List::removeNode(Node* node) {
    if (node == head) {
        head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    delete node;
};

void List::printList() {
    Node* current = head;
    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
};

class Hashtable {
public:
    List* table; // Lista de ponteiros de nós
    int size; // Tamanho da tabela

    Hashtable(int s) {
        size = s;
        table = new List[s];
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hash(key);
        table[index].insertNode(key);
    }

    void remove(int key) {
        int index = hash(key);
        Node* currentNode = table[index].head;
        while (currentNode != NULL) {
            if (currentNode->data == key) {
                table[index].removeNode(currentNode);
                return;
            }
            currentNode = currentNode->next;
        }
    }
};

void List::removeDuplicates() {
    Hashtable hashTable(100); // Tabela de dispersão com tamanho 100
    Node* currentNode = head;
    while (currentNode != NULL) {
        if (hashTable.table[hashTable.hash(currentNode->data)].head != NULL) {
            // Se já existe um nó na lista correspondente à posição na tabela de dispersão,
            // removemos o nó da lista original.
            hashTable.remove(currentNode->data);
            Node* temp = currentNode;
            currentNode = currentNode->next;
            if (temp == head) {
                head = currentNode;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else {
                temp->prev->next = currentNode;
                if (currentNode != NULL) {
                    currentNode->prev = temp->prev;
                }
            }
            delete temp;
        } else {
            // Se não existe nenhum nó na lista correspondente à posição na tabela de dispersão,
            // inserimos o nó na lista e adicionamos na tabela de dispersão.
            hashTable.insert(currentNode->data);
            currentNode = currentNode->next;
        }
    }
};

int main(){

  std::default_random_engine generator;
  std::normal_distribution<float> distribution(500.0,100.0);

  // Create a list
  List l;

  // Number of elements to store
  int nbElements = 100;

  // Random number to save
  int number;

  // Fill the list
  for (int i = 0; i < nbElements; i ++)
  {
    // Generate a new random number
    number = distribution(generator);
    // Add a node to the list
    l.insertNode(number);
  }

  cout << "Original list" << endl;
  l.printList();

  // Remove the duplicates in the list
  l.removeDuplicates();


  cout << "Modified list" << endl;
  l.printList();

  return 0;
}