
#include<iostream>

using namespace std;

int main(void){
	int numBancos, numDeb;

	cin >> numBancos >> numDeb;

	while(numBancos && numDeb){
		//leitura das reservas
		int reservas[numBancos];
		for(int i = 0; i < numBancos; i++){
			cin >> reservas[i];
		}

		//leitura das dividas
		for(int i = 0; i < numDeb; i++){
			int bancoDevedor, bancoCredor, valor;
			cin >> bancoDevedor >> bancoCredor >> valor;

			reservas[bancoDevedor-1] -= valor;
			reservas[bancoCredor-1]  += valor;
		}

		//checagem se todos vão conseguir quitar as dividas
		int conseguiram = 1;
		for(int i = 0; conseguiram && i < numBancos; i++){
			if(reservas[i] < 0){
				conseguiram = 0;
			}
		}
		if(conseguiram){
			cout << 'S';
		}else{
			cout << 'N';
		}
		cout << endl;
		cin >> numBancos >> numDeb;
	}

	return 0;
}
