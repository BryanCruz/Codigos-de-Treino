#include<iostream>

using namespace std;

int main(void){
	int pontuacao, qtdFases;
	cin >> pontuacao >> qtdFases;

	for(int i = 0; i < qtdFases; i++){
		int pontuacaoFase;
		cin >> pontuacaoFase;

		pontuacao += pontuacaoFase;
		if(pontuacao > 100){
			pontuacao = 100;
		}else if(pontuacao < 0){
			pontuacao = 0;
		}
	}

	cout << pontuacao << "\n";

	return 0;
}
