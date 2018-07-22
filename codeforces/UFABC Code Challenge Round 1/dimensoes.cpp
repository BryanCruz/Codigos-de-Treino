#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void){
	int n, m;
	cin >> n >> m;

	int numLinhas, numColunas;
	cin >> numLinhas >> numColunas;

	int matriz[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> matriz[i][j];
		}
	}	

	int maiorSoma = 0;
	for(int i = 0; i <= n-numLinhas; i++){
		for(int j = 0; j <= m-numColunas; j++){
			int somaAtual = 0;
			for(int k = 0; k < numLinhas; k++){
				for(int l = 0; l < numColunas; l++){
					somaAtual += matriz[i+k][j+l];
				}
			}

			if(somaAtual > maiorSoma){
				maiorSoma = somaAtual;
			}
		}
	}

	cout << maiorSoma << endl;
	return 0;
}
