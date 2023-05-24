#ifndef crud
#define  crud
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
typedef struct aluno{

  char nome[50];
  int matricula;
  char curso[50];
  char email[50];
  char orientador[50];
  char frequencia[50];

} aluno_tipo;

typedef struct avaliador {
  char nome[50];
  char instituicao[100];
  char email[50];
} avaliador_type;

typedef struct dados_da_banca {
  char titulo[50];
  char resumo[100];
  char horario[50];
  char local[100];
} banca_type;

typedef class tcc {
  private:
  aluno_tipo aluno;
  int quantidade_avaliador;
  avaliador_type avaliador[10];
  banca_type banca;
public:
void set_aluno(tcc &auxiliar){
  cout << "nome do aluno: ";
  cin.getline(auxiliar.aluno.nome, 50);
  cout << "numero da matricula: ";
  cin >> auxiliar.aluno.matricula;
  cin.ignore();
  cout << "nome do curso: ";
  cin.getline(auxiliar.aluno.curso, 50);
  cout << "e-mail do aluno: ";
  cin.getline(auxiliar.aluno.email, 50);
  cout << "digite o nome do orientador ";
  cin.getline(auxiliar.aluno.orientador, 50);
  cout << "digite a frequencia ";
  cin.getline(auxiliar.aluno.frequencia, 50);
}
void set_qtdAvaliador(int numero){
  quantidade_avaliador = numero;
  
}

void set_avaliador(tcc &auxiliar){
    for (int i = 0; i < quantidade_avaliador; i++) {
    cout << "\nnome do " << i + 1 << "º avaliador ";
    cin.getline(auxiliar.avaliador[i].nome, 50);
    cout << "nome da instituição: ";
    cin.getline(auxiliar.avaliador[i].instituicao, 100);
    cout << "e-mail do avaliador: ";
    cin.getline(auxiliar.avaliador[i].email, 50);
  }
}
void set_banca(tcc &auxiliar) {
  cout << "\ntitulo da banca: ";
  cin.getline(auxiliar.banca.titulo, 50);
  cout << "resumo: ";
  cin.getline(auxiliar.banca.resumo, 100);
  cout << "horario: ";
  cin.getline(auxiliar.banca.horario, 50);
  cout << "local: ";
  cin.getline(auxiliar.banca.local, 100);
}
aluno_tipo get_aluno(){
  return aluno;
}
int get_qtdAvaliador(){
 
  return quantidade_avaliador;
}
avaliador_type get_avaliador(int i){
  return avaliador[i];
}
banca_type get_banca(){
  return banca;
}
} tcc;

void cadastrar();
void arquiva_queue(queue<tcc> auxiliar, int tamanho);
int size_file();
void lixeira(tcc auxiliar);
void menu();
void ler_imprimi_tudo();
void imprimi_posicao(int posicao);
void atualizar(int tamanho);
void deletar(int tamanho);
#endif