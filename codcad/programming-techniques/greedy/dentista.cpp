#include<iostream>
#include<algorithm>

using namespace std;

struct Consulta{
  int horaInicio;
  int horaTermino;
};

bool comparar(Consulta a, Consulta b){
  return a.horaTermino < b.horaTermino;
}

int main() {
  int n;
  cin >> n;

  Consulta consultas[n];

  for(int i = 0; i < n; i++){
    cin >> consultas[i].horaInicio >> consultas[i].horaTermino;
  }

  sort(consultas, consultas+n, comparar);

  int qtdRealizadas = 0;
  int ultimoHorarioLivre = 0;

  for(int i = 0; i < n; i++){
    if(consultas[i].horaInicio >= ultimoHorarioLivre){
      qtdRealizadas++;
      ultimoHorarioLivre = consultas[i].horaTermino;
    }
  }

  cout << qtdRealizadas << endl;
}de												
