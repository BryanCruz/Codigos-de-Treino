#include <bits/stdc++.h>

using namespace std;

typedef struct aluno aluno;
struct aluno{
	bool state;
	char direction; 
	int number;
}

void virar(char * d){
	if(*d == 'U'){
		*d  = 'R';
	}else if(*d  == 'R'){
		*d  = 'D';
	}else if(*d == 'D'){
		*d  = 'L';
	}else{
		*d  = 'U';
	}	
}


void executarInstrucoes(){
	//virar(&c);
}

int main(){
	int n;
	cin >> n;
	

	int i, j;
	cin >> a;
	cin >> b;

	aluno m[n][n];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> aluno[m][n].shirt;
			aluno[i][j].state = 0;
			aluno[i][j].direction = 'U';
		}
	}
}
