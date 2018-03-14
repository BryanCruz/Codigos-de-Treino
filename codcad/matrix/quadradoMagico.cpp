#include<iostream>

using namespace std;

int main(void){
	int n; 
	cin >> n;
	
	//leitura
	int matriz[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> matriz[i][j];
		}
	}

	//checagem
	int somaLinhas[n];
	int somaColunas[n];
	int somaDiagonais[2] = {0, 0};

	for(int i = 0; i < n; i++){
		somaLinhas[i] = 0;
		somaColunas[i] = 0;
	}

	int somasIguais = 1;

	for(int i = 0; somasIguais && i < n; i++){
		for(int j = 0; j < n; j++){
			somaLinhas[i] += matriz[i][j];

			if(i == j){
				somaDiagonais[0] += matriz[i][j];
			}
			if(i == n-j-1){
				somaDiagonais[1] += matriz[i][j];
			}
		}

		somasIguais = somaLinhas[i] == somaLinhas[0];
	}
	somasIguais = somasIguais && somaDiagonais[0] == somaLinhas[0];
	somasIguais = somasIguais && somaDiagonais[1] == somaLinhas[0];
	for(int i = 0; somasIguais && i < n; i++){
		for(int j = 0; j < n; j++){
			somaColunas[i] += matriz[j][i];
		}

		somasIguais = somaColunas[i] == somaLinhas[0];
	}

	if(somasIguais){
		cout << somaLinhas[0];
	}else{
		cout << "-1";
	}
	cout << endl;
	return 0;
}
