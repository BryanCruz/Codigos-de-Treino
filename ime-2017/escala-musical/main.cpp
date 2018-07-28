#include<iostream>
#include<algorithm>

using namespace std;

int QTD_NOTAS  = 12;
int QTD_PADRAO = 7;

int inserirNoSet(int x, int * s, int n){
	for(int i = 0; i < n; i++){
		if(s[i] == x) return 0;
	}

	s[n] = x;
	return 1;
}

int * geradorDePadrao(int deslocamento){
	int gerador[] = {2, 2, 1, 2, 2, 2, 1};
	int * gerado = new int[7];
	gerado[0] = deslocamento;
	for(int i = 1; i < QTD_PADRAO; i++){
		gerado[i] = (gerado[i-1]+gerador[i-1]) % QTD_NOTAS;
	}

	return gerado;
}

int comp(int a, int b){
	return a < b;
}


int taDentro(int * v1, int n1, int * v2, int n2){
	int i = 0, deslocamento = 0;
	for(deslocamento = 0; deslocamento < n2; deslocamento++){
		if(v1[0] == v2[deslocamento]) break;
	}

	int j = 0;
	while(i < n1 && j < QTD_PADRAO){
		if(v1[i] == v2[(j + deslocamento) % QTD_PADRAO]){
			i++;
			j++;
		}else{
			j++;
		}
	}

	if(i < n1) return -1;
	else 	   return v2[0];
}

string acharPadrao(int acordes){
	string valores[] = {
		"do",
		"do#",
		"re",
		"re#",
		"mi",
		"fa",
		"fa#",
		"sol",
		"sol#",
		"la",
		"la#",
		"si"
	};

	return valores[acordes];
}

int main(void){
	//leitura dos dados
	long n;
	cin >> n;

	int acordesTocados[12];
	int tmp;
	int iTocados = 0;
	for(long i = 0; i < n; i++){
		cin >> tmp;
		iTocados += inserirNoSet((tmp-1) % QTD_NOTAS, acordesTocados, iTocados);
	}

	int isPattern = 0;
	int deslocamento = 0;
	if(iTocados <= 7){
		sort(acordesTocados, acordesTocados + iTocados, comp);
		for(int i = 0; i < QTD_NOTAS && !isPattern; i++){
			if((deslocamento = taDentro(acordesTocados, iTocados, geradorDePadrao(i), QTD_PADRAO)) != -1){
				isPattern = 1;
			}
		}
	}

	string c = "desafinado";
	if(isPattern){
		c = acharPadrao(deslocamento);
	}
	
	cout << c << endl;

	return 0;
}
