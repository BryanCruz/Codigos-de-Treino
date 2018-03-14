#include<iostream>
#include<cmath>

using namespace std;

int main(void){
	int largura, altura, profundidade, raio;
	cin >> largura >> altura >> profundidade >> raio;

	int diametroAoQuadrado = 4*raio*raio;

	int diagonalAoQuadrado = altura*altura + largura*largura + profundidade * profundidade;
	
	if(diametroAoQuadrado >= diagonalAoQuadrado){
		cout << 'S';
	}else{
		cout << 'N';
	}

	cout << endl;

	return -0;
}
