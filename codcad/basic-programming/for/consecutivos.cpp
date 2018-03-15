#include<iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;

	int valorAnterior, valorAtual, maiorSequencia = 0, sequenciaAtual = 1;
	cin >> valorAnterior;
	for(int i = 1; i < n; i++){
		cin >> valorAtual;

		if(valorAtual == valorAnterior){
			sequenciaAtual++;
		}else{
			if(sequenciaAtual > maiorSequencia){
				maiorSequencia = sequenciaAtual;
			}
			sequenciaAtual = 1;
		}

		int tmp = valorAnterior;
		valorAnterior = valorAtual;
		valorAtual = tmp;
	}
		
	if(sequenciaAtual > maiorSequencia){
		maiorSequencia = sequenciaAtual;
	}

	cout << maiorSequencia << "\n";
	return 0;
}
