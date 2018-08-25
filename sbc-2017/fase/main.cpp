// https://www.urionlinejudge.com.br/judge/pt/problems/view/2663

#include<iostream>
#include<algorithm>

using namespace std;

int comp(int a, int b){
	return a > b;
}

int main(void){
	int N, K;
	cin >> N >> K;

	int jogadores[N];
	
	for(int i = 0; i < N; i++){
		cin >> jogadores[i];
	}	

	sort(jogadores, jogadores+N, comp);

	int classificados = K-1;
	int valorClassificados = jogadores[classificados];
	while(++classificados < N){
		if(jogadores[classificados] != valorClassificados) break;
	}
	
	cout << classificados << endl;
	return 0;
}
