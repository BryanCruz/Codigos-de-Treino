#include<iostream>

using namespace std;

int main(void){
	int dias, saldo;
	cin >> dias >> saldo;
	
	int menorSaldo = saldo;
	while(dias-- > 0){
		int mudanca;
		cin >> mudanca;

		saldo += mudanca;
		if(saldo < menorSaldo){
			menorSaldo = saldo;
		}
	}
	
	cout << menorSaldo << "\n";
	return 0;
}
