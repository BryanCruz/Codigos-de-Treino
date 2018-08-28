#include<stdio.h>
#include<stdlib.h>

int comp(const void * a, const void * b){
	return (*(int*)a > *(int*)b);
}

int printVetor(int * vetor, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

char * seqName(int value){
	char * c;
	switch(value){
		case 0:
			c = "do\0";
			break;
		
		case 1:
			c = "do#\0";
			break;
		
		case 2:
			c = "re\0";
			break;
		
		case 3:
			c = "re#\0";
			break;
		
		case 4:
			c = "mi\0";
			break;
		
		case 5:
			c = "fa\0";
			break;
		
		case 6:
			c = "fa#\0";
			break;
		
		case 7:
			c = "sol\0";
			break;
		
		case 8:
			c = "sol#\0";
			break;
		
		case 9:
			c = "la\0";
			break;
		
		case 10:
			c = "la#\0";
			break;
		
		default:
			c = "si\0";
			break;
	}

	return c;
}

int pattern[] = {2, 2, 1, 2, 2, 2, 1};
int patternSize = 7;
int qtdNotas = 12;

int * geradorDePatterns(int notaInicial) {
	int * newPattern = (int*) malloc((patternSize+1)* sizeof(int));
	newPattern[0] = notaInicial; 

	for(int i = 1; i <= patternSize; i++){
		newPattern[i] = (newPattern[i-1] + pattern[i-1]) % qtdNotas;
	}

	return newPattern;
}

int diffNotas(int a, int b){
	int diff = b - a;
	diff = (diff < qtdNotas - diff) ? diff : qtdNotas - diff;

	return diff;
}

int checkPattern(int * somePattern, int x){
	printVetor(somePattern, patternSize);
	int isPattern = 1;
	for(int i = 0; i < 7 && isPattern; i++){
		isPattern = somePattern[i] == pattern[(i+x) % patternSize];
	}

	return isPattern;
}

int main(void) {
	for(int i = 0; i < 12; i++){
		printVetor(geradorDePatterns(i), patternSize+1);
	}
	printf("----\n");

	long n;
	scanf("%ld", &n);

	// le as notas
	int notas[n];
	for(long i = 0; i < n; i++){
		int nota;
		scanf("%d", &nota);
		notas[i] = (nota-1) % 12;
	}

	// transforma em um vetor de notas individuais
	qsort(notas, n, sizeof(int), comp);
	int notasInd[12];
	int iNotasInd = 0;
	notasInd[iNotasInd++] = notas[0];
	long i;
	for(i = 1; i < n; i++){
		while(notas[i] == notas[i-1] && i < n) i++;
		if(i == n) break;

		notasInd[iNotasInd++] = notas[i];
	}	

	printVetor(notasInd, iNotasInd);

	int isPattern = 0;



	char * patternName;
	if(!isPattern){
		patternName = "desafinado\0";
	}else{
		patternName = seqName(notas[0] + i - 1); 
	}

	printf("%s\n", patternName);
	return 0;
}


