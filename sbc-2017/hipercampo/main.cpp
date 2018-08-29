// https://www.urionlinejudge.com.br/judge/en/problems/view/2665

#include<stdio.h>
#include<algorithm>

using namespace std;

struct ponto{
	int x;
	int y;
};

int comp(ponto p1, ponto p2){
	return p1.y > p2.y;
}

void imprimirPontos(ponto * p, int n){
	for(int i = 0; i < n; i++){
		printf("(%d, %d)\n", p[i].x, p[i].y);
	}
}

int main(void){
	int n, xa, xb;
	scanf("%d %d %d", &n, &xa, &xb);

	ponto p[n];
	for(int i = 0; i < n; i++){
		scanf("%d %d", &(p[i].x), &(p[i].y));
	}
	
	//imprimirPontos(p, n);
	sort(p, p+n, comp);
	
	//imprimirPontos(p, n);



	return 0;
}
