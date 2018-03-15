#include<iostream>

using namespace std;

int fatorial(int n){
	if(n <= 1){
		return 1;
	}else{
		return fatorial(n-1)*n;
	}
}

int main(void){
	int n;
	cin >> n;

	cout << fatorial(n) << endl;

	return 0;
}
