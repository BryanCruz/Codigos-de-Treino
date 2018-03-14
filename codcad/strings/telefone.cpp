#include<iostream>

using namespace std;

int main(void){
	string numTelefone;
	cin >> numTelefone;

	//conversao
	string numTelefoneConvertido = "";
	string tabelaConversao[9] = {"", "ABC", "DEF", "GHI", "JKL",
							    "MNO", "PQRS", "TUV", "WXYZ"};

	for(int i = 0; i < numTelefone.size(); i++){
		int convertido = 0;
		for(int j = 0; !convertido && j < 9; j++){
			for(int k = 0; !convertido && k < tabelaConversao[j].size(); k++){
				if(numTelefone[i] == tabelaConversao[j][k]){
					numTelefoneConvertido += '1'+j;
					convertido = 1;
				}
			}
		}


		if(!convertido){
			numTelefoneConvertido += numTelefone[i];
		}
	}
	
	cout << numTelefoneConvertido << endl;
	return 0;
}
