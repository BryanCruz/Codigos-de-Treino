#include<iostream>
#include<algorithm>

int QTD_NOTAS = 12
int QTD_PADRAO = 7

using namespace std;

int inserirNoSet(int x, int * s, int n){
	for(int i = 0; i < n; i++){
		if(s[i] == x) return 0;
	}

	s[n] = x;
	return 1;
}

int geradorDePadrao(int deslocamento){
	int gerador[] = {2, 2, 1, 2, 2, 2, 1};
	
	
}

int comp(int a, int b){
	return a < b;
}

int main(void){
	//leitura dos dados
	long n;
	scanf("%d", &n);

	int acordesTocados[12];
	int tmp;
	int iTocados = 0;
	for(long i = 0; i < n; i++){
		scanf("%d", &tmp);
		iTocados += inserirNoSet((tmp-1) % QTD_NOTAS, acordesTocados, iTocados);
	}

	int isPattern = 0;
	if(iTocados <= 7){
		sort(acordesTocados, acordesTocados + iTocados, comp);
		for(int i = 0; i < iTocados; i++){
			printf("%d ", acordesTocados[i]);

	}

	

	return 0;
}
