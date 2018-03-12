#include<iostream>

using namespace std;

int main(void){
	//tamanho do vetor
	int n;
	cin >> n;
	int territorios[n];

	//leitura dos dados
	for(int i = 0; i < n; i++){
		cin >> territorios[i];
	}

	//dividir o vetor tal que ambas as partes tenham o mesmo tamanho
	int somaEsquerda = 0, somaDireita = 0;
	for(int i = 0; i < n; i++){
		somaDireita += territorios[i];
	}

	int index = 0;
	while(somaEsquerda < somaDireita){
		somaEsquerda += territorios[index];
		somaDireita  -= territorios[index];

		index++;
	}

	cout << index << endl;
	return 0;
}
