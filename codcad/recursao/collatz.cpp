#include<iostream>

using namespace std;
int qtd = 0;

int collatz(int n){
	qtd++;
	if(n == 1){
		return 1;
	}else if(n % 2 == 0){
		return collatz(n/2);
	}else{
		return collatz(3*n + 1);
	}
}

int main(void){
	int n;
	cin >> n;

	collatz(n);

	cout << --qtd << endl;
	return 0;
}
