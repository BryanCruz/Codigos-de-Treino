#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void){
	int n;
	cin >> n;

	//leitura
	int colecao[n];
	for(int i = 0; i < n; i++){
		cin >> colecao[i];
	}
	
	//sort
	sort(colecao, colecao+n);

	//exibicao
	int primeiro = 1;
	for(int i = 0; i < n; i++){
		if(colecao[i]%2 == 0){
			if(primeiro) primeiro = 0;
			else		 cout << " ";

			cout << colecao[i];
		}
	}
	cout << endl;

	primeiro = 1;
	for(int i = n-1; i >= 0; i--){
		if(colecao[i]%2 == 1){
			if(primeiro) primeiro = 0;
			else		 cout << " ";

			cout << colecao[i];
		}
	}
	cout << endl;
	return 0;
}
