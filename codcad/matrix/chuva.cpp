#include<iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	
	//leitura
	int periodo1[n][n], periodo2[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> periodo1[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> periodo2[i][j];
		}
	}

	//exibicao do resultado
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			cout << periodo1[i][j]+periodo2[i][j] << " ";
		}
		cout << periodo1[i][n-1]+periodo2[i][n-1] << endl;
	}

	return 0;
}
