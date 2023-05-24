#include "crud.hpp"

void arquivo(tcc auxiliar) {
  fstream file("arquivo_tcc.bin", ios::binary | ios::app);

  file.write((char *)&auxiliar, sizeof(tcc) * 1);

  file.close();
}

void arquiva_queue(queue<tcc> auxiliar, int tamanho) {
  fstream file("arquivo_tcc.bin", ios::binary | ios::app);
  if (!file) {
    cout << "não foi possivel guardar!";
  } else {
    for (int i = 0; i < tamanho; i++) {

      file.write((char *)&auxiliar.front(), sizeof(tcc) * 1);
      auxiliar.pop();
    }
  }
  file.close();
}


void lixeira(tcc auxiliar) {
  fstream file("lixeira_tcc.bin", ios::binary | ios::app);

  file.write((char *)&auxiliar, sizeof(tcc) * 1);

  file.close();
}

void cadastrar() {
  tcc auxiliar;
  int qtd_avaliador;
  auxiliar.set_aluno(auxiliar);
  cout << "digite a quantidade de avaliadores ";
  cin >> qtd_avaliador;
  auxiliar.set_qtdAvaliador(qtd_avaliador);
  cin.ignore();
  auxiliar.set_avaliador(auxiliar);
  auxiliar.set_banca(auxiliar);
  arquivo(auxiliar);
}
int size_file() {
  fstream file("arquivo_tcc.bin", ios::binary | ios::in);
  int tamanho = 0;
  if (!file) {
    cout << "\no arquivo esta vazio ou não foi encontrado!\n";
    return -1;
  } else {
    tcc auxiliar;
    while (file.read((char *)&auxiliar, sizeof(tcc) * 1) && !file.eof()) {
      tamanho++;
    }
  }
  file.close();
  return tamanho;
}