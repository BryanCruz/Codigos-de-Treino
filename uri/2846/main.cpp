#include<iostream>
#define MAX 200000

int fibonot[MAX];

void generate(int k){
	int a     = 1;
	int b     = 2;
	int count = 1;
	int tmp, i;

	while(b < MAX){
		for(i = a; i < b; i++){
			fibonot[i] = count;
		}
		count++;
		tmp = b;
		b   = a+b;
		a   = tmp;
	}
}

int find(int n){
    int curr = 0;
	int next = fibonot[n];
	int diff = next-curr;

	while(diff != 0){
        n   += diff;
        curr = next;
        next = fibonot[n];
        diff = next-curr;
	}

	return n;
}

int main(void){
	std::ios_base::sync_with_stdio(false);
	
	int k;
	std::cin >> k;

	generate(k);

	std::cout << find(k) << std::endl;

	return 0;
}

