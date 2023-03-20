#include <iostream>
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

  // Iniciando uma árvore binária
  BinaryTree T;
  Node * node1 = new Node(8);
  Node * node2 = new Node(6);
  Node * node3 = new Node(10);

  // Adição de novos dados
  T.insertNode(node1);
  T.insertNode(node2);
  T.insertNode(node3);

  // Impressão de dados contidos na árvore
  T.printTree(T.root);
  cout << endl;

  // Busca de dado a partir de uma chave
  Node * searchNode = T.treeSearch(7);
  if(searchNode != NULL) {
    cout << "Valor encontrado! Dado: " << searchNode->data << endl;
  } else {
    cout << "Valor não está presente na árvore binária" << endl;
  }

  // Eliminação de dado
  T.treeDelete(node3);

  // Nova árvore
  T.printTree(T.root);

  return 0;
}
