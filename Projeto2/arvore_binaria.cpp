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


int main () {
  BinaryTree T;
  Node * node1 = new Node(8);
  Node * node2 = new Node(6);
  Node * node3 = new Node(10);

  T.insertNode(node1);
  T.insertNode(node2);
  T.insertNode(node3);

  cout << T.root->data << endl;
  cout << T.root->left->data << endl;
  cout << T.root->right->data << endl;

  T.printTree(T.root);

  // Node searchNode = T.treeSearch(6);
  // if(searchNode != NULL) {
  //   cout << "valor encontrado! " << searchNode.data << endl;
  // }

  // cout << T->root->left << endl;
  // cout << T->root->right << endl;



  return 0;
}

// void BinaryTree::addNode (int number) {
//     Node * newNode = new Node(number);
//     Node * node = root;
//     if(root == NULL) {
//       root = newNode;
//     } else {
//     //left
//       if(number < root->data) {
//         node = node->left;
//         while(node != NULL) {
//           if(number < node->data) {
//             if(node->left == NULL) {
//               node->left = newNode;
//               node->left->p = node;
//               return;
//             }
//             node = node->left;
//           } else {
//             if(node->right == NULL) {
//               node->right = newNode;
//               node->right->p = node;
//               return;
//             }
//             node = node->right;
//           }
//         }
//       } else {
//         node = node->right;
//         while(node != NULL) {
//           if(number < node->data) {
//             if(node->left == NULL) {
//               node->left = newNode;
//               node->left->p = node;
//               return;
//             }
//             node = node->left;
//           } else {
//             if(node->right == NULL) {
//               node->right = newNode;
//               node->right->p = node;
//               return;
//             }
//             node = node->right;
//           }
//         }
//       }
//   }
// };
