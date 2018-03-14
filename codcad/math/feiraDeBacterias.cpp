#include<iostream>
#include<cmath>

using namespace std;

int main(void){
	int n;
	cin >> n;

	int valores[n];
	int expoentes[n];

	//leitura dos dados
	for(int i = 0; i < n; i++){
		cin >> valores[i] >> expoentes[i];
	}
	double maior = 0;
	int iMaior = -1;
	for(int i = 0; i < n; i++){
		double valorCalculado = expoentes[i]*log(valores[i]);
		if(valorCalculado > maior){
			maior = valorCalculado;
			iMaior = i;
		}
	}
	
	cout << iMaior << endl;
	return 0;
}
