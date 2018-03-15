#include<iostream>

using namespace std;

int main(void){
	int qtdTipos;
	cin >> qtdTipos;
	
	int menorQtd;
	cin >> menorQtd;
	for(int i = 1; i < qtdTipos; i++){
		int qtdAtual;
		cin >> qtdAtual;

		if(qtdAtual < menorQtd){
			menorQtd = qtdAtual;
		}
	}

	cout << menorQtd << "\n";
	return 0;
}
