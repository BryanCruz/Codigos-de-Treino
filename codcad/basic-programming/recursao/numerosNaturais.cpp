#include<iostream>

using namespace std;

int somatorioZeroAteN(int n){
	if(n <= 0){
		return 0;
	}else{
		return somatorioZeroAteN(n-1) + n;
	}
}

int main(void){
	int n;
	cin >> n;

	cout << somatorioZeroAteN(n) << endl;

	return 0;
}
