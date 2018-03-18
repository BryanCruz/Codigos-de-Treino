#include <iostream>

using namespace std;

int MOEDAS[] = {1, 5, 10, 25, 50, 100};

int main(void){
  int troco;
  cin >> troco;

  int n = 6; //existem 6 moedas
  int qtdMoedas = 0;

  for(int i = n-1; i >= 0; i--){
    int qtdMoedasAtual = troco/MOEDAS[i];
    troco -= qtdMoedasAtual * MOEDAS[i];

    qtdMoedas  += qtdMoedasAtual;
  }

  cout << qtdMoedas << endl;
  return 0;
}
