#include<iostream>

using namespace std;

int main(void){
	int size; 
	cin >> size;
	
	string gabarito, respostas;
	cin >> gabarito >> respostas;
	
	int acertos = 0;
	for(int i = 0; i < size; i++){
		if(gabarito[i] == respostas[i]){
			acertos++;
		}
	}

	cout << acertos << endl;
	return 0;
}
