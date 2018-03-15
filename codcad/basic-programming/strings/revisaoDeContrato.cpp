#include<iostream>

using namespace std;

int main(void){
	string digito, valor;

	while(cin >> digito >> valor && digito[0] != '0' && valor[0] != '0'){
		string resultado = "";
		//conversao
		for(int i = 0; i < valor.size(); i++){
			if(valor[i] != digito[0]){
				resultado += valor[i];
			}
		}

		//tirar os zeros
		int zerosAEsquerda = 1, i;
		for(i = 0; i < resultado.size() && resultado[i] == '0'; i++);

		if(i == resultado.size()){
			resultado = "0";
			i = 0;
		}
		
		while(i < resultado.size()){
			cout << resultado[i];
			i++;
		}
		cout << endl;
	}
	return 0;
}
