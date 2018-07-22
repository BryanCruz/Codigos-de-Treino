#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void){
	int t;
	cin >> t;

	while(t-- > 0){
		int x;
		cin >> x;
	
		int estacoesPassadas, distanciaAtual, estacaoAnterior = 0;
		for(estacoesPassadas = 0, distanciaAtual = 1; distanciaAtual < x; distanciaAtual += estacoesPassadas+1){
			estacoesPassadas++;
			estacaoAnterior = distanciaAtual;
		}
		
		int distanciaApe;
		int dist1 = x - estacaoAnterior, dist2 = distanciaAtual - x;
		if(dist1 < dist2+1){
			distanciaApe = dist1;
			estacoesPassadas--;
		}else{
			distanciaApe = dist2;
		}

		int tempoTotal = 1 + estacoesPassadas + distanciaApe;
		cout << tempoTotal << endl;
	}

	return 0;
}
