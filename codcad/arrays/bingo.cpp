
#include<iostream>

using namespace std;

int main(void){
	//numero de bolas totais e restantes na urna
	int numTotal, numRestantes;
	cin >> numTotal >> numRestantes;
	
	while(numTotal != 0 && numRestantes != 0){
		//leitura dos valores na urna
		int restantes[numRestantes];
		for(int i = 0; i < numRestantes; i++){
			cin >> restantes[i];
		}

		//checar valores que podem ser chamados
		int valores[numTotal];
		for(int i = 0; i < numTotal; i++){
			valores[i] = 0;
		}
		for(int i = 0; i < numRestantes; i++){
			for(int j = i+1; j < numRestantes; j++){
				int dif = restantes[j]-restantes[i];
				if(dif < 0){
					dif = -dif;
				}
				valores[dif-1] = 1;
			}
		}
		//checar se todos os valores podem ser chamados
		int podem = 1;
		for(int i = 0; podem && i < numTotal; i++){
			podem = valores[i];
		}
		
		if(podem){
			cout << 'Y';
		}else{
			cout << 'N';
		}
		cout << endl;
		
		cin >> numTotal >> numRestantes;
	}
	return 0;
}
