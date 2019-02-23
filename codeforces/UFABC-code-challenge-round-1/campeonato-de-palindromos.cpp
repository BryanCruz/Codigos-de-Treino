#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

bool checarPalindromo(string palavra, int i, int j){
	bool palindromo = true;
	while(palindromo && j > i){
		palindromo = palavra[i++] == palavra[j--];
	}

	return palindromo;
}

int main(void){
	int n;
	cin >> n;

	string palavra;
	cin >> palavra;

	int maiorTam = 0, iMaior = 0;

	int i, j;
	for(i = n-1; i >= 0; i--){
		for(j = 0; j <= i; j++){
			bool palindromo = checarPalindromo(palavra, j, i);

			if(palindromo){
				int tam = i-j+1;
				if(tam >= maiorTam){
					maiorTam = tam;
					iMaior = j;
				}
			}
		}
	}

	cout << maiorTam << endl;
	for(int k = 0; k < maiorTam; k++){
		cout << palavra[iMaior+k];
	}
	cout << endl;
	return 0;
}
