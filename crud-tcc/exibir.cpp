
#include "crud.hpp"

using namespace std;

void imprimir_aluno(tcc auxiliar_tcc){
  aluno_tipo auxiliar =auxiliar_tcc.get_aluno();
  cout << "\n   dados do aluno\n";
  cout << "nome: " << auxiliar.nome << " "
       << "matricula: " << auxiliar.matricula << endl;
  cout << "curso: " << auxiliar.curso << " "
       << "email: " << auxiliar.email << endl;
  cout << "orientador: " << auxiliar.orientador << " "
       << "frequencia: " << auxiliar.frequencia << endl;
}
void imprimir_banca(tcc auxiliar_tcc) {
  banca_type auxiliar = auxiliar_tcc.get_banca();
  cout << "\n   dados da banca  " << endl
       << "titulo: " << auxiliar.titulo << endl;
  cout << "local: " << auxiliar.local << endl;
  cout << "resumo: " << auxiliar.resumo << endl;
  cout << "horario: " << auxiliar.horario << endl;
}
void imprimir_avaliador(tcc auxiliar_tcc) {
  avaliador_type avaliador[auxiliar_tcc.get_qtdAvaliador()];
  cout << "\n   dados dos avaliadores\n";
  for (int i = 0; i < auxiliar_tcc.get_qtdAvaliador(); i++) {
    avaliador[i]=auxiliar_tcc.get_avaliador(i);
    cout << "\nnome: " << avaliador[i].nome << endl;
    cout << "intituiçao: " << avaliador[i].instituicao << endl;
    cout << "email: " << avaliador[i].email << endl;
  }
}
void ler_imprimi_tudo() {
  int posicao = 0;
  fstream file("arquivo_tcc.bin", ios::binary | ios::in);
  tcc recebe;
  if (!file) {
    cout << "\no arquivo esta vazio ou não foi encontrado!\n";

  } else {
    while (file.read((char *)&recebe, sizeof(tcc) * 1) && !file.eof()) {

      cout << "\n************"
           << " posicao " << ++posicao << " *********" << endl;
      imprimir_aluno(recebe);
      imprimir_banca(recebe);
      imprimir_avaliador(recebe);
    }
  }
  file.close();
}

void imprimi_posicao(int posicao) {
  if (posicao < 1 || posicao > size_file()) {
    cout << "\nposicao inesistente! " << endl;
  } else {
    int contador = 1;
    fstream file("arquivo_tcc.bin", ios::binary | ios::in);
    tcc recebe;
    if (!file) {
      cout << "\no arquivo esta vazio ou não foi encontrado!\n";

    } else {
      while (file.read((char *)&recebe, sizeof(tcc) * 1) && !file.eof()) {
        if (contador == posicao) {
          cout << "\n*********************" << endl;
          imprimir_aluno(recebe);
          imprimir_banca(recebe);
          imprimir_avaliador(recebe);
        }
        contador++;
      }
    }
    file.close();
  }
}

void menu() {
  cout << "\n**************\n";
  cout << "[ 1 ] -> cadastrar\n[ 2 ] -> imprime\n[ 3 ] -> atualizar\n[ 4 ] -> "
          "deleta\n[ 0 ] -> sair ";
  cout << "\n**************\n";
}
