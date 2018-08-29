// https://www.urionlinejudge.com.br/judge/pt/problems/view/2667

#include<stdio.h>

int main(void){
	char c[111];
	scanf("%s", c);

	int total = 0;
	for(int i = 0; c[i] != '\0'; i++){
		total += (int) (c[i] - '0');

	}

	printf("%d\n", total%3);
	return 0;
}
