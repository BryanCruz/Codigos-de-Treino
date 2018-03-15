#include <iostream>
#include <algorithm>
using namespace std;

struct Carros{
  int id;
  int tempoTotal;
};

bool comparar(Carros a, Carros b){
  return a.tempoTotal < b.tempoTotal;
}

int main() {
  int numCarros, numVoltas;
  cin >> numCarros >> numVoltas;
  
  Carros carros[numCarros];
  for(int i = 0; i < numCarros; i++){
    carros[i].id = i+1;
    carros[i].tempoTotal = 0;
  }
  
  for(int i = 0; i < numCarros; i++){
    for(int j = 0; j < numVoltas; j++){
      int tempo;
      cin >> tempo;
      carros[i].tempoTotal += tempo;
    }
  }
  
  sort(carros, carros+numCarros, comparar);
  
  for(int i = 0; i < 3; i++){
    cout << carros[i].id << endl;
  }
  return 0;
}
