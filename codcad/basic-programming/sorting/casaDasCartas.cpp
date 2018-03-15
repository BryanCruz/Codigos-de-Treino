#include<iostream>
#include<algorithm>

using namespace std;

struct Lucros{
	int vampirao;
	int deputados;
};

bool checagem(Lucros a, Lucros b){
	bool result;
	if(a.vampirao > b.vampirao){
		result = true;
	}else if(a.vampirao == b.vampirao){
		result = a.deputados > b.deputados;	
	}else{
		result = false;
	}

	return result;
}

int main(void){
	int n, m;
	
	cin >> n >> m;

	//leitura dos valores
	int v[n];
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	//calculo do melhor
	Lucros lucros[n];

	for(int i = 0; i < n; i++){
		lucros[i].deputados = v[i] / m;				//deputados
		lucros[i].vampirao = v[i] - m*lucros[i].deputados;   //vampirao
	}

	sort(lucros, lucros+n, checagem);


	for(int i = 0; i < n; i++){
		if(i > 0) cout << " ";
		cout << (lucros[i].deputados*m+lucros[i].vampirao);
	}
	cout << endl;
	return 0;
}
