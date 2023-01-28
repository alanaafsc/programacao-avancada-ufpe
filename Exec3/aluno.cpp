#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

class Aluno {
    string nome;
    float *listaDeNotas;
    public:
    int numeroNotas;
    public:
        Aluno() {};
        Aluno(string);
        void adicionarNota() {
            listaDeNotas = new float[numeroNotas];
            for(int i = 0; i < numeroNotas; i++) {
                cout << "Adicione a nota " << i + 1 << " do aluno: ";
                cin >> listaDeNotas[i];
            }
            cout << "Notas adicionadas!" << endl;
        };
    float calcularMedia() {
        float soma;
        for(int i = 0; i < numeroNotas; i++) {
            soma += listaDeNotas[i];
        }
        float media = soma/numeroNotas;
        return media;
    };
    string getNome() {
        return nome;
    }
};

Aluno::Aluno(string nomeAluno) {
    nome = nomeAluno;
}

int main () {

int qntdAlunos;
int qntdNotas;
cout << "Qual a quantidade de alunos? ";
cin >> qntdAlunos;
cout<<endl;

cout << "Qual a quantidade de notas por aluno? ";
cin >> qntdNotas;
cout<<endl;

Aluno alunos[qntdAlunos];
cout << "Digite o nome dos alunos: " << endl;
for(int j = 0; j < qntdAlunos; j ++) {
    
    string nome;
    cout << "Nome do aluno " << j + 1 << ": ";
    cin >> nome;
    Aluno aluno(nome);
    aluno.numeroNotas = qntdNotas;
    alunos[j] = aluno;
}
cout<<endl;

cout << "Preencha as notas dos alunos: " << endl;
for(int i = 0; i < qntdAlunos; i++) {
    cout << "Preencha as notas do aluno " << i + 1 << endl;
    alunos[i].adicionarNota();
}
cout<<endl;

cout << "MÉDIAS DOS ALUNOS: " << endl;
for(int k = 0; k < qntdAlunos; k++){
    cout << "Aluno: " << alunos[k].getNome() << " - ";
    cout << "Média: " << alunos[k].calcularMedia() << endl;
}

return 0;
}