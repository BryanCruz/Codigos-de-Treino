// https://www.urionlinejudge.com.br/judge/pt/problems/view/2661

#include<iostream>

using namespace std;

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

unsigned long long permutaPrimos(int n, int p){
	if(n == p) return 1;

	int upperBound = max(p, n-p);
	int lowerBound = min(p, n-p);

	unsigned long long total = 1;
	int i = upperBound+1, j = 2;

	while(i <= n || j <= lowerBound){
		if(i <= n) total*=i++;
		while(j <= lowerBound && total%j == 0) total /= j++;
	}

	return total;
}


int main(void){
	unsigned long long n;
	cin >> n;

	int primos = 0;
	for(unsigned long long i = 2; i*i <= n; i++){
		if(n % i == 0) {
			primos++;
			while(n % i == 0){
				n /= i;
			}
		}
	}
	
	if(n > 1) primos++;
	unsigned long long total = 0;
	for(int i = 2; i <= primos; i++){
		total += permutaPrimos(primos, i);
	}
	
	cout << total << endl;;

	return 0;
}
