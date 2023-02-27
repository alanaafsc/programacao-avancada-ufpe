#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Node {
public:
  float data[2];
  Node* next;
  Node(float x1, float x2) {
    data[0] = x1;
    data[1] = x2;
  }
};


void inserirItem(Node*& node, float x1, float x2) {
    Node* nodeNovo = new Node(x1, x2);
    nodeNovo->next = node;
    node = nodeNovo;
}

void imprimirLista(Node* node) {

    Node* item = node;

    while (item != NULL) {
        cout << item->data[0] << ", " << item->data[1] << endl;
        item = (*item).next;
    }
}

Node* encontrarItem(Node* node, float x1, float x2) {
    Node* item = node;
    while (node != NULL) {
        if (node->data[0] == x1 && node->data[1] == x2) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void deletarItem(Node*& node, float x1, float x2) {
    Node* item = node;
    Node* itemNull = NULL;
    while (item != NULL) {
        if (item->data[0] == x1 && item->data[1] == x2) {
            if (itemNull == NULL) {
                node = item->next;
            } else {
                itemNull->next = item->next;
            }
            delete item;
            return;
        }
        itemNull = item;
        item = item->next;
    }
}

int main (){
  
  string fileName = "dados.txt";
  ifstream file;
  file.open(fileName);

  Node *head = NULL;

  float x1, x2;
  string line;
  if(file.is_open()) {
    while(getline(file, line)) {
      istringstream ss(line);
      ss >> x1 >> x2;
      inserirItem(head, x1, x2);
    }
  }

  file.close();

  cout << "Imprimir lista" << endl;
  imprimirLista(head);

  float valor1, valor2;
  cout << "Inserir elementos do item na lista, digite o primeiro valor: ";
  cin >> valor1;
  cout << "Digite o segundo valor: ";
  cin >> valor2;

  inserirItem(head, valor1, valor2);
  imprimirLista(head);

  float valor1procurar, valor2procurar;
  cout << "Digite o item a ser procurado na lista: " << endl;
  cout << "Primeiro valor: ";
  cin >> valor1procurar;
  cout << "Segundo valor: ";
  cin >> valor2procurar;
  Node* item = encontrarItem(head, valor1procurar, valor2procurar);

  if(item == NULL) {
    cout << "Esse item não existe na lista" << endl;
  } else {
    cout << "Item encontrado: " << item->data[0] << " " << item->data[1] << endl;
  }

  float deletarValor1, deletarValor2;
  cout << "Digite o item que deseja deletar. Primeiro valor do item: ";
  cin >> deletarValor1;
  cout << "Segundo valor: ";
  cin >> deletarValor2;

  deletarItem(head, deletarValor1, deletarValor2);
  cout << "Lista atualizada: " << endl;
  imprimirLista(head);

  return 0;

};
