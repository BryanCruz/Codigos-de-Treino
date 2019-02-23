#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

string ** estante;
int maxLivros, livro, n, m;

void colocarLivro(int i, int j){
	if(livro > maxLivros || i < 0 || i >= n || j < 0 || j >= m || estante[i][j][0] != '.'){
		return;
	}

	estante[i][j] = to_string(livro++);
	colocarLivro(i-1, j);
	colocarLivro(i, j+1);
	colocarLivro(i+1, j);
	colocarLivro(i, j-1);
}

int main(void){
	int linhaInicial, colunaInicial;
	cin >> n >> m >> linhaInicial >> colunaInicial >> maxLivros;

	estante = new string * [n];
	for(int i = 0; i < n; i++){
		estante[i] = new string[m];
		for(int j = 0; j < m; j++){
			cin >> estante[i][j];
		}
	}

	livro = 1;
	colocarLivro(linhaInicial, colunaInicial);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(j > 0) cout << " ";
			cout << estante[i][j];
		}
		cout << endl;
	}
	return 0;
}
