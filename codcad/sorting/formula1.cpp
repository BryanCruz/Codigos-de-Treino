#include<iostream>
#include<algorithm>

using namespace std;

struct Piloto{
	int id;
	int pontuacao;	
	int * colocacoes;		//colocacoes em cada corrida
};

bool checagem(Piloto a, Piloto b){
	bool result;
	if(a.pontuacao > b.pontuacao){
		result = true;
	}else if(a.pontuacao < b.pontuacao){
		result = false;
	}else{
		result = a.id < b.id;
	}
	return result;
}
int main(void){
	int numCorridas, numPilotos;
	while(cin >> numCorridas >> numPilotos && numCorridas > 0 && numPilotos > 0){
		
		Piloto pilotos[numPilotos];
		for(int i = 0; i < numPilotos; i++){
			pilotos[i].id = i+1;
			pilotos[i].colocacoes = new int[numCorridas];
		}
		
		//ordem de chegada dos pilotos
		for(int corrida = 0; corrida < numCorridas; corrida++){
			for(int piloto = 0; piloto < numPilotos; piloto++){
				cin >> pilotos[piloto].colocacoes[corrida];
			}
		}

		//ler e exibir as colocacoes em cada sistema
		int numSistemas;
		cin >> numSistemas;	

		for(int sistema = 0; sistema < numSistemas; sistema++){
			for(int piloto = 0; piloto < numPilotos; piloto++){
				pilotos[piloto].pontuacao = 0;
			}

			int qtdPosicoesSistema;
			cin >> qtdPosicoesSistema;

			int pontuacoesSistema[qtdPosicoesSistema];
			for(int pontuacao = 0; pontuacao < qtdPosicoesSistema; pontuacao++){
				cin >> pontuacoesSistema[pontuacao];
			}

			for(int corrida = 0; corrida < numCorridas; corrida++){
				for(int piloto = 0; piloto < numPilotos; piloto++){
					int posicaoPiloto = pilotos[piloto].colocacoes[corrida]-1;
					if(posicaoPiloto < qtdPosicoesSistema){
						pilotos[piloto].pontuacao += pontuacoesSistema[posicaoPiloto];
					}
				}
			}

			sort(pilotos, pilotos+numPilotos, checagem);

			int anterior = pilotos[0].pontuacao;
			for(int i = 0; i < numPilotos && pilotos[i].pontuacao == anterior; i++){
				if(i > 0) cout << " ";
				cout << pilotos[i].id;

				anterior = pilotos[i].pontuacao;
			}
			cout << endl;
		}


	}

	return 0;
}
