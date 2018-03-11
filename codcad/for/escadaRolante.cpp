#include<iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;

	int tempoTotal = 0, tempoAnterior, tempoAtual;
	cin >> tempoAnterior;
	tempoTotal += 10;

	for(int i = 1; i < n; i++){
		cin >> tempoAtual;
		
		if(tempoAtual >= tempoAnterior+10){
			tempoTotal += 10;
		}else{
			tempoTotal += tempoAtual - tempoAnterior;
		}

		tempoAnterior = tempoAtual;
	}

	cout << tempoTotal << "\n";
	return 0;	
}
