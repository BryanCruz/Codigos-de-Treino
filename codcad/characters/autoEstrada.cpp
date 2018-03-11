#include<iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;

	int qtd = 0;
	for(int i = 0; i < n; i++){
		char c; 
		cin >> c;
	
		if(c == 'P' || c == 'C'){
			qtd += 2;
		}else if(c == 'A'){
			qtd += 1;
		}
	}

	cout << qtd << "\n";
	return 0;
}
