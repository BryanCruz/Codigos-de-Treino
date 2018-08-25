#include<iostream>

// https://www.urionlinejudge.com.br/judge/pt/problems/view/2664

int quantity(int actual, int counter, int min, int max) {
	if(actual < min || actual > max) return 0;
	if(counter == 1) return 1;
	return (quantity(counter-1, actual-1, min, max) + quantity(counter-1, actual+1, min, max)) % (10e9 + 7);
}

int main(void){
	int T, M, N;
	cin >> T >> M >> N;

	int total = 0;
	for(int i = M; i <= N; i++){
		total += (quantity(i, T, M, N) % (10e9 + 7)); 
	}

	cout << total << endl;

	return 0;
}
