
#include "crud.hpp"


void deletar(int tamanho) {
  int posicao, contador = 1;
  queue<tcc> fila;
  cout << "digite a posicao para remover ";
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
          lixeira(auxiliar);
          cout << "\nremovido!" << endl;
        } else {
          fila.push(auxiliar);
        }
        contador++;
      }
      remove("arquivo_tcc.bin");
      if (fila.size()) {
        arquiva_queue(fila, tamanho - 1);
      }
    }
    file.close();
  }
}