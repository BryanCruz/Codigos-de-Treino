#include<iostream>
#include<algorithm>

using namespace std;

struct Paises{
	int medalhas[3];
	int id;
};

bool classificar(Paises a, Paises b){
	bool decidido = false;
	int med;
	for(med = 0; !decidido && med < 3; med++){
		decidido = !(a.medalhas[med] == b.medalhas[med]);
	}
	bool resultado;
	if(!decidido){
		resultado = a.id < b.id;
	}else{
		med--;
		resultado = a.medalhas[med] > b.medalhas[med];
	}
	
	return resultado;
}

int main(){
	int numPaises, numModalidades;
	cin >> numPaises >> numModalidades;
	
	//inicializacao do vetor de paises
	Paises paises[numPaises];
	for(int i = 0; i < numPaises; i++){
		for(int j = 0; j < 3; j++){
			paises[i].medalhas[j] = 0;
		}
		
		paises[i].id = i + 1;
	}
	
	//leitura das medalhas
	for(int i = 0; i < numModalidades; i++){
		for(int med = 0; med < 3; med++){
			int tmp;
			cin >> tmp;
			
			paises[tmp-1].medalhas[med]++;
		}
	}
	
	//sorting
	sort(paises, paises + numPaises, classificar);
	
	//exibicao
	for(int i = 0; i < numPaises; i++){
		if(i > 0) cout << ' ';
		cout << paises[i].id;
	}
	cout << endl;
	return 0;
}
