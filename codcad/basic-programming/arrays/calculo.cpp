#include<iostream>

using namespace std;

int main(void){
	//leitura do tamanho dos valores
	int m, n;
	cin >> m >> n;
	
	int num1[m];
	int num2[n];

	//leitura dos valores
	for(int i = 0; i < m; i++){
		cin >> num1[i];	
	}

	for(int i = 0; i < n; i++){
		cin >> num2[i];	
	}
	
	//somar os valores
	int maior = m > n ? m : n;
	int result[maior];
	int carry = 0;

	for(int i = maior-1; i >= 0; i--){
		result[i] = carry;
		carry = 0;

		if(i < m){
			result[i] += num1[i];
		}
		if(i < n){
			result[i] += num2[i];
		}
		if(result[i] > 1){
			result[i] -= 2;
			carry = 1;
		}
	}

	int zerosADireita = 0;
	for(int i = maior-1; result[i] == 0; i--){
		zerosADireita++;
	}
	for(int i = 0; i < maior-1-zerosADireita; i++){
		cout << result[i] << " ";
	}
	cout << result[maior-1-zerosADireita] << endl;

	return 0;
}
