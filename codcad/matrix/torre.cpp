#include<iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	
	//leitura
	int	matriz[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> matriz[i][j];
		}
	}

	//calculo dos pesos
	int somaLinhas[n];
	int somaColunas[n];
	for(int i = 0; i < n; i++){
		somaLinhas[i]  = 0;
		somaColunas[i] = 0;
		for(int j = 0; j < n; j++){
			somaLinhas[i]  += matriz[i][j];
			somaColunas[i] += matriz[j][i];
		}
	}

	int maiorPeso = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int pesoAtual = somaLinhas[i] + somaColunas[j] - 2*matriz[i][j];
			if(pesoAtual > maiorPeso){
				maiorPeso = pesoAtual;
			}
		}
	}
	
	cout << maiorPeso << endl;
	return 0;
}
