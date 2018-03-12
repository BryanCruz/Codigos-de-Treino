#include<iostream>

using namespace std;

int main(void){
	//tamanho do tabuleiro
	int n;
	cin >> n;
	
	//leitura dos dados
	int tabuleiro[n];
	for(int i = 0; i < n; i++){
		cin >> tabuleiro[i];
	}

	//calculo da vizinhanca
	int vizinhancas[n];
	for(int i = 0; i < n; i++){
		int qtd = 0;
		for(int j = i-1; j <= i+1; j++){
			if(j < 0 || j >= n){
			
			}else if(tabuleiro[j]){
				qtd++;
			}
		}
		vizinhancas[i] = qtd;
	}

	//exibicao
	for(int i = 0; i < n; i++){
		cout << vizinhancas[i] << endl;
	}
	return 0;
}
