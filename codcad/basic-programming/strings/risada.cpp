#include<iostream>

using namespace std;

int main(void){
	string risada;
	cin >> risada;
	
	int n = risada.size();
	int palindroma = 1;
	for(int i = -1, j = n; palindroma && i < j;){
		char c;
		do{		
			c = risada[++i];
		}while(i < j && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
		char d;
		do{
			d = risada[--j];
		}while(j > i && d != 'a' && d != 'e' && d != 'i' && d != 'o' && d != 'u');
		
		if(i < j && c != d){
			palindroma = 0;
		}
	}
	
	cout << (palindroma? 'S' : 'N') << endl;
	return 0;
}
