#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node* p;
    Node (int number) {
        data = number;
        left = NULL;
        right = NULL;
        p = NULL;
    };
};

class BinaryTree {
public:
    Node * root;
    BinaryTree() {
      root = NULL;
    };
    void insertNode (Node * newNode);
    void printTree(Node * root);
    Node * treeSearch(int number);
    void transplant(Node * u, Node * v);
    Node * treeMinimum(Node * node);
    void treeDelete(Node * node);
};

void BinaryTree::insertNode(Node * newNode) {
  Node * temp = root;
  Node * y = NULL;
  while(temp != NULL) {
    y = temp;
    if (newNode -> data < temp->data){
      temp = temp->left;
    } else {
      temp = temp -> right;
    }
  }
  newNode->p = y;
  if(y == NULL) {
    root = newNode; //arvore vazia
  } else if(newNode->data < y->data){
    y->left = newNode;
  } else {
    y->right = newNode;
  }

};

void BinaryTree::printTree(Node * root) {
  if(root != NULL) {
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
  }
};

Node * BinaryTree::treeSearch(int number) {
  Node * temp = root;
  while (temp != NULL && number != temp->data) {
    if (number < temp->data) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }
  return temp;
};

void BinaryTree::transplant(Node * u, Node * v) {
  if(u->p == NULL) {
    root = v;
  } else if(u == u->p->left) {
    u->p->left = v;
  } else {
    u->p->right = v;
  }

  if(v != NULL) {
    v->p = u->p; 
  }
};

Node * BinaryTree::treeMinimum(Node * node) {
  while(node->left != NULL) {
    node = node->left;
  }
  return node;
};

void BinaryTree::treeDelete (Node * node) {
  if(node->left == NULL) {
    transplant(node, node->right);
  } else if(node->right == NULL) {
    transplant(node, node->left);
  } else {
    Node * y = treeMinimum(node->right);
    if(y->p != node) {
      transplant(y, y->right);
      y->right = node->right;
      y->right->p = y;
    }
    transplant(node, y);
    y->left = node->left;
    y->left->p = y;
  }
};


int main () {
  string fileName = "data.txt";
  ifstream file;
  file.open(fileName);

  // Iniciando uma árvore binária
  BinaryTree T;

  string line;
  int x1;
  // Construir uma árvore de busca binária contendo todos os dados contidos no arquivo data.txt
  if(file.is_open()) {
    while(getline(file, line)) {
      istringstream ss(line);
      ss >> x1;
      Node * node = new Node(x1);
      T.insertNode(node);
    }
  }

  file.close();

  // Nova árvore
  T.printTree(T.root);
  cout << endl;

  // Procurar na árvore de busca binária os dados armazenados no arquivo search.txt
  string lineSearch;
  int x2;

  string fileNameSearch = "search.txt";
  ifstream fileSearch;
  fileSearch.open(fileNameSearch);

  if(fileSearch.is_open()) {
    while(getline(fileSearch, lineSearch)) {
      istringstream ss(lineSearch);
      ss >> x2;
      Node * searchNode = T.treeSearch(x2);
      cout << "Valor a ser procurado: " << x2 << endl;
      if(searchNode != NULL) {
        cout << "Valor encontrado! Dado: " << searchNode->data << endl;
      } else {
        cout << "Valor não está presente na árvore binária" << endl;
      }
    }
  }

  fileSearch.close();

  // Eliminar os dados armazenados no arquivo delete.txt.
  string fileNameDelete = "delete.txt";
  ifstream fileDelete;
  fileDelete.open(fileNameDelete);

  string lineDelete;
  int x3;

  if(fileDelete.is_open()) {
    while(getline(fileDelete, lineDelete)) {
      istringstream ss(lineDelete);
      ss >> x3;
      Node * node = T.treeSearch(x3);
      cout << "Valor a ser deletado: " << x3 << endl;
      T.treeDelete(node);
    }
  }

  fileDelete.close();
  // Nova árvore alterada
  T.printTree(T.root);
  cout << endl;

  return 0;
}
