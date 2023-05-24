
#include "crud.hpp"


void modificar(tcc &auxiliar) {
  char comando[2];
  cout << "oque voce quer modificar " << endl;
  cout << "[1] - dados aluno " << endl;
  cout << "[2] - dados avaliadores" << endl;
  cout << "[3] - dados da banca" << endl;
  cin.getline(comando, 2);
  switch (comando[0]) {
  case '1': {
    auxiliar.set_aluno(auxiliar);
    break;
  }
  case '2': {
    auxiliar.set_avaliador(auxiliar);
    break;
  }
  case '3': {
    auxiliar.set_banca(auxiliar);
    break;
  }
  default: {
    cout << "comando incorreto! \n"
         << "nada foi atualizado!" << endl;
  }
  }
}


void atualizar(int tamanho) {
  int posicao, contador = 1;

  queue<tcc> fila;
  cout << "digite a posicao ";
  cin >> posicao;
  cin.ignore();
  if (posicao < 1 || tamanho < posicao) {
    cout << "\nposição não encontrada\n";
  } else {
    fstream file("arquivo_tcc.bin", ios::binary | ios::in);

    if (!file) {
      cout << "\no arquivo esta vazio ou não foi encontrado!\n";
    } else {
      tcc auxiliar;
      while (file.read((char *)&auxiliar, sizeof(tcc) * 1) && !file.eof()) {
        if (posicao == contador) {
          modificar(auxiliar);
        }
        fila.push(auxiliar);
        contador++;
      }
      remove("arquivo_tcc.bin");
      arquiva_queue(fila, tamanho);
    }
    file.close();
  }
}
