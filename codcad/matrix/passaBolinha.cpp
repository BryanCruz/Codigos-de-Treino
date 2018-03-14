#include<iostream>

using namespace std;

void girar(char * direcao){
	switch(*direcao){
		case 'U':
			*direcao = 'R';
			break;
		case 'R':
			*direcao = 'D';
			break;
		case 'D':
			*direcao = 'L';
			break;
		case 'L':
			*direcao = 'U';
	}
}

//recebeu bolinha:
//	levanta bandeira
//	4 vezes
//		gira 90º sentido horario
//		if(colega >= voce)
//			passaBolinha e espera ser devolvida
//	devolve a bolinha
//
//
void passarBolinha(int n, int linha, int coluna, int ** numCamisetas, char ** direcoes, int ** bandeirasLevantadas){
	bandeirasLevantadas[linha][coluna] = 1;
	for(int i = 0; i < 4; i++){
		girar(&direcoes[linha][coluna]);
		int linhaAlvo = linha, colunaAlvo = coluna;
		switch(direcoes[linha][coluna]){
			case 'U':
				colunaAlvo++;
				break;
			case 'R':
				linhaAlvo++;
				break;
			case 'D':
				colunaAlvo--;
				break;
			case 'L':
				linhaAlvo--;
				break;
		}
		if(linhaAlvo >= 0 && linhaAlvo < n && colunaAlvo >= 0 && colunaAlvo < n){
			if(numCamisetas[linhaAlvo][colunaAlvo] >= numCamisetas[linha][coluna] && !bandeirasLevantadas[linhaAlvo][colunaAlvo])
				passarBolinha(n, linhaAlvo, colunaAlvo, numCamisetas, direcoes, bandeirasLevantadas);
		}
	}
}

int main(void){
	int n;
	cin >> n;
	int ** numCamisetas = new int *[n];	
	for(int i = 0; i < n; i++)
		numCamisetas[i] = new int[n];
	int ** bandeirasLevantadas = new int *[n];	
	for(int i = 0; i < n; i++)
		bandeirasLevantadas[i] = new int[n];
	char ** direcoes = new char *[n];	
	for(char i = 0; i < n; i++)
		direcoes[i] = new char[n];


	int iInicial, jInicial;
	cin >> iInicial >> jInicial;
	
	//inicializacao dos vetores
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> numCamisetas[i][j];
			bandeirasLevantadas[i][j] = 0;
			direcoes[i][j] = 'U';
		}
	}
	

	passarBolinha(n, --iInicial, --jInicial, numCamisetas, direcoes, bandeirasLevantadas);
	
	//contagem
	int qtd = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(bandeirasLevantadas[i][j])
				qtd++;
		}
	}

	//exibicao 
	cout << qtd << endl;
	return 0;
}
