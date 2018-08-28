#include<stdio.h>

#define MAX_PRIMOS 1000000

int primos[MAX_PRIMOS];
long long n;
int countPrimos;

void calcularPrimos(){
	for(int i = 2; i*i <= n; i++){
		if(primos[i] == 0){
			for(int j = 0; i*i + i*j <= n; j++){
				primos[i*i+i*j] = 1;
			}
			countPrimos++;
		}
	}
}

int max(int a, int b){
	return a > b ? a : b;
}

long long permuta(int v, int p){
	long long result = 1;

	int maxV = max(p, v-p);
	int minV = maxV == p ? n-p : p;

	while(v > maxV){
		result *= v;
		v--;
	}

	while(minV > 1){
		result /= minV;
		minV--;
	}

	return result;
}

long long permutaTudo(int v){
	long long total = 0;

	for(int i = 2; i <= n; i++){
		total += permuta(v, i);
	}

	return total;
}

int main(void){
	while(scanf("%ll", &n) != EOF){
		countPrimos = 0;
		calcularPrimos();	
		
		printf("%ll\n", permutaTudo(countPrimos));
	}
	return 0;
}
