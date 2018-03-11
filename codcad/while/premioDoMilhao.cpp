#include<iostream>

using namespace std;

int main(){
	int meta = 1e6, visitas = 0, qtdDeDias = 1;
	
	int n;
	cin >> n;
	while(n-- > 0){
		int visitasDoDia;
		cin >> visitasDoDia;
		visitas += visitasDoDia;
		if(visitas < meta){
			qtdDeDias++;
		}
	}

	cout << qtdDeDias << "\n";
	return 0;
}
