#include<iostream>
#include<algorithm>

using namespace std;

int m, n;
int matrix[101][101];

int getElement(int i, int j){
	if(i < 0 || i >= n || j < 0 || j >= m){
		return -1;
	}
	return matrix[i][j];
}

int min(int a, int b){
	if(a < 0 && b < 0){
		return 0;
	}else{
		return a > b? a : b;
	}
}

int main(void){
	int t;
	cin >> t;

	while(t-- > 0){
		//reading
		cin >> n >> m;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}

		//restoring
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(matrix[i][j] < 0){
					int lastLine = getElement(i-1, j);
					int lastColumn = getElement(i, j-1);

					matrix[i][j] = max(lastLine, lastColumn);
				}		
			}
		}
			
		bool check = true;
		for(int i = 1; check && i < n; i++){
			for(int j = 1; check && j < m; j++){
				check = matrix[i][j] >= matrix[i-1][j] && matrix[i][j] >= matrix[i][j-1];
			}
		}


		//printing
		if(check){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(j > 0) cout << " ";
					cout << matrix[i][j];
				}
				cout << endl;
			}
		}else{
			cout << "-1" << endl;
		}
	}

	return 0;
}
