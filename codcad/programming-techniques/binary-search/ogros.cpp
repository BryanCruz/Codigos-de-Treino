#include<iostream>

using namespace std;

struct premiacao{
	int valor;
	int faixaMin;
};

int buscarValor(int faixa, premiacao * premiacoes, int n){
	int ini = 0, fim = n-1, mid;
	while(ini <= fim){
		mid = ini + (fim - ini)/2;
		if(faixa >= premiacoes[mid].faixaMin && (mid == n-1 || faixa < premiacoes[mid+1].faixaMin)){
			return premiacoes[mid].valor;
		}else{
			if(faixa >= premiacoes[mid].faixaMin){
				ini = mid+1;
			}else{
				fim = mid-1;
			}
		}
	}
}

int main(void){
	int numFaixas, numOgros;
	cin >> numFaixas >> numOgros;

	premiacao premiacoes[numFaixas];
	
	premiacoes[0].faixaMin = 0;
	for(int i = 1; i < numFaixas; i++){
		cin >> premiacoes[i].faixaMin;
	}

	for(int i = 0; i < numFaixas; i++){
		cin >> premiacoes[i].valor;
	}
	
	int pontosOgros[numOgros];
	for(int i = 0; i < numOgros; i++){
		cin >> pontosOgros[i];
	}

	for(int i = 0; i < numOgros; i++){
		if(i > 0) cout << " ";
		cout << buscarValor(pontosOgros[i], premiacoes, numFaixas);
	}
	cout << endl;
	return 0;
}
