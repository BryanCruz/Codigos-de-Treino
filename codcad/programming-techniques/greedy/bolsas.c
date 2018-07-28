#include<stdio.h>
#include<stdlib.h>

typedef struct bolsa bolsa;
struct bolsa{
	int duracao;
	int entrega;
};

int comp(const void * a, const void * b){
	printf("%d %d\n", (*(bolsa*)a).entrega, ((*(bolsa*)b).entrega ));
	return ((*(bolsa*)a).entrega < (*(bolsa*)b).entrega);
}

int max(int a, int b){
	return a > b? a : b;
}

int atraso(bolsa b, int tempoAtual){
	return max(0, tempoAtual + b.duracao - b.entrega);
}

int maiorAtraso(bolsa * bolsas, int qtdBolsas){
	int tempoAtual  = 0;
	int maiorAtrasoTmp = 0;

	for(int i = 0; i < qtdBolsas; i++){
		maiorAtrasoTmp = max(atraso(bolsas[i], tempoAtual), maiorAtrasoTmp);
		tempoAtual    += bolsas[i].duracao;
	}

	return maiorAtrasoTmp;
}

int main(void){
	// leitura dos dados
	int qtdBolsas;
	scanf("%d", &qtdBolsas);

	bolsa bolsas[qtdBolsas];
	for(int i = 0; i < qtdBolsas; i++){
		scanf("%d %d", &(bolsas[i].duracao), &(bolsas[i].entrega)); 
	}

	for(int i = 0; i < qtdBolsas; i++){
		printf("%d ", bolsas[i].entrega);
	}
	printf("\n");
	qsort(bolsas, qtdBolsas, sizeof(bolsa), comp);
	for(int i = 0; i < qtdBolsas; i++){
		printf("%d ", bolsas[i].entrega);
	}

	printf("\n");
	printf("%d\n", maiorAtraso(bolsas, qtdBolsas));
	
	return 0;
}
