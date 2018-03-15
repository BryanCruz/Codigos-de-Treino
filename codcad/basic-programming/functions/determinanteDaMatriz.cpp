#include<iostream>
#include<cmath>

using namespace std;

int det(int m[][3]){
	int det = 0;
	
	for(int i = 0; i < 3; i++){

		int indexLinha = i;
		int indexColuna = 0;
		int tmp = 1;
		for(int j = 0; j < 3; j++){
			tmp *= m[indexLinha][indexColuna];
			indexLinha++;
			indexColuna++;

			if(indexLinha >= 3){
				indexLinha -= 3;
			}
		}
	
		
		det += tmp;

	}
	for(int i = 0; i < 3; i++){
		int indexLinha = i;
		int indexColuna = 2;
		int tmp = 1;
		for(int j = 0; j < 3; j++){
			tmp *= m[indexLinha][indexColuna];
			indexLinha++;
			indexColuna--;

			if(indexLinha >= 3){
				indexLinha -= 3;
			}
		}
	
		
		det -= tmp;

	}
	return det;
}

int main(void){
	int m[3][3];

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> m[i][j];
		}
	}

	cout << det(m) << endl;
	return 0;
}
