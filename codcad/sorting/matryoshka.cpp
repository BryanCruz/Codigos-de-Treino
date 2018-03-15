#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	int n;
	cin >> n;

	int bonecas[n];
	int copiaBonecas[n];
	for(int i = 0; i < n; i++){
		cin >> bonecas[i];
		copiaBonecas[i] = bonecas[i];
	}

	sort(copiaBonecas, copiaBonecas+n);

	int qtd = 0;
	int bonecasASeremRetiradas[n];

	for(int i = 0; i < n; i++){
		if(bonecas[i] != copiaBonecas[i]){
			bonecasASeremRetiradas[qtd++] = bonecas[i];
		}
	}

	cout << qtd << endl;
	sort(bonecasASeremRetiradas, bonecasASeremRetiradas+qtd);
	for(int i = 0; i < qtd; i++){
		if(i != 0) cout << " ";
		cout << bonecasASeremRetiradas[i];
	}
	cout << endl;
	return 0;
}
