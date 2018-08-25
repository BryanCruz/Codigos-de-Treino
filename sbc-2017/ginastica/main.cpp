// https://www.urionlinejudge.com.br/judge/pt/problems/view/2664

#include<iostream>

#define TMAX 51
#define VMAX 100001

using namespace std;

// MATRIZ[TEMPO_INICIAL][V_INICIAL]
int saveQtt[TMAX][VMAX];

void initializeMatrix(int T, int min, int max){
	for(int i = 0; i < TMAX; i++){
		for(int j = 0; j < VMAX; j++){
			saveQtt[i][j] = 0;
		}
	}

	for(int i = min; i <= max; i++){
		saveQtt[1][i] = 1;
	}
}

int main(void){

	int T, M, N;
	cin >> T >> M >> N;
	
	initializeMatrix(T, M, N);
	
	for(int j = 2; j <= T; j++){
		for(int i = M; i <= N; i++){
			int v = 0;
			v += saveQtt[j-1][i-1];
			v += saveQtt[j-1][i+1];
			saveQtt[j][i] = v % 1000000007;
		}
	}

	int total = 0;
	for(int i = M; i <= N; i++){
		total = (total + saveQtt[T][i]) % 1000000007;
	}
	cout << total << endl;

	return 0;
}
