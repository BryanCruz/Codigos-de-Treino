#include<stdlib.h>
#include<stdio.h>
int QTD_NOTAS = 12;

typedef struct noLigado * noLigado;
struct noLigado {
	int valor;	
	noLigado prox;
};

void adicionaNo(noLigado * lista, noLigado no){
	if(*lista == NULL){
		*lista = no; 
	}else{
		noLigado cabeca = *lista;
		while(lista->prox != cabeca){
		
		}
	}
}

int main(void){
	long n;
	scanf("%ld", &n);

	int tmp;
	int notas[n];
	for(long i = 0; i < n; i++){
		scanf("%d", &tmp);
		notas[i] = (tmp-1) % QTD_NOTAS;
	}

	
	return 0;
}
