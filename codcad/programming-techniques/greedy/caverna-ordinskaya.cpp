#include <iostream>

using namespace std;

int main(void) {
  //qtd de mergulhos e comprimento da fita
  int qtd, comp;
  cin >> qtd >> comp;

  //leitura
  int medicoes[qtd];
  for(int i = 0; i < qtd; i++){
    cin >> medicoes[i];
  }

  //calculo da soma
  long long soma = 0;
  int anterior = 0;

  for(int i = 0; soma >= 0 && i < qtd; i++){
    int medicao = medicoes[i];
    int invMedicao = comp - medicao;

    //verifica qual a menor distancia possivel
    int qtdExplorada;
    if(medicao <= invMedicao){
      qtdExplorada = medicao;
    }else{
      qtdExplorada = invMedicao;
      invMedicao = medicao;
    }

    //verifica se a distancia explorada e maior que as anteriores
    if(qtdExplorada < anterior){
      qtdExplorada = invMedicao;
    }
    if(qtdExplorada < anterior){
      soma = -1;
      qtdExplorada = 0;
    }

    //salva a qtd explorada no valor total
    soma += qtdExplorada;
    anterior = qtdExplorada;
  }


  cout << soma << endl;
}
