#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void){
	int somaAlvo, numCasas;

	cin >> numCasas;
	int casas[numCasas];
	for(int i = 0; i < numCasas; i++){
		cin >> casas[i];
	}

	int soma = -1;
	int ini = 0, fim = numCasas-1;

	cin >> somaAlvo;
	
	while(soma != somaAlvo){
		soma = casas[ini] + casas[fim];

		if(soma > somaAlvo){
			fim--;
		}else if(soma < somaAlvo){
			ini++;
		}
	}
	
	cout << casas[ini] << " " << casas[fim]	<< endl;
	return 0;
}
