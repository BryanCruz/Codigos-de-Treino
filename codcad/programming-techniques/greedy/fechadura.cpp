#include<iostream>
#include<algorithm>

using namespace std;

int abs(int x){
  if(x < 0) x = -x;

  return x;
}

int main(void){
  int numPinos, alturaCorreta;
  cin >> numPinos >> alturaCorreta;

  int pinos[numPinos];
  for(int i = 0; i < numPinos; i++){
    cin >> pinos[i];
  }

  //1 mov = 2 pinos seguidos movidos em 1mm
  int qtdMov = 0;

  //alinhar os pinos
  for(int i = 0; i < numPinos-1; i++){
    int mudancaDeAltura = alturaCorreta - pinos[i];
    pinos[i] += mudancaDeAltura;
    pinos[i+1] += mudancaDeAltura;

    qtdMov += abs(mudancaDeAltura);
  }

  cout << qtdMov << "\n";

  return 0;
}f
