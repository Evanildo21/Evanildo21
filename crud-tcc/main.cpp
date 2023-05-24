
#include "crud.hpp"

void esqueleto_de_comandos() {

  string operador;
  do {
    menu();
    cin>>operador;
    cin.ignore();
    switch (operador[0]) {

    case '1': {
      cadastrar();
      break;
    }
    case '2': {
      int tamanho_do_arquivo = size_file();
      if (tamanho_do_arquivo > 0) {
        char condicao[2];
        cout << "voce que imprimir tudo o que esta no arquivo?\n[ s ] sim\n[ n "
                "] não\n ";
        cin.getline(condicao, 2);
        if (condicao[0] == 's') {
          ler_imprimi_tudo();
        } else {
          int posicao;
          cout << "digite o numero da posição dos dados que deseja imrimir ";
          cin >> posicao;
          imprimi_posicao(posicao);
          cin.ignore();
        }
      }
      break;
    }
    case '3': {
      int tamanho = size_file();
      if (tamanho > 0) {
        atualizar(tamanho);
      }
      break;
    }
    case '4': {
      int tamanho_do_arquivo = size_file();
      if (tamanho_do_arquivo > 0) {

        deletar(tamanho_do_arquivo);
      }
      break;
    }
    case '0': {
      cout << "saindo ...";
      break;
    }

    default: {
      cout << "\n\tcomando incorreto!\n";
      
      break;
    }
    }
  } while (operador != "0");
}

int main() {

  esqueleto_de_comandos();
  return 0;
}