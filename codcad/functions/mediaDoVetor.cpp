#include <iostream>
#include <iomanip>

using namespace std;

double media_vetor(int n, int v[]){
	double media;
	for(int i = 0; i < n; i++){
		media += 1.0*v[i]/n;
	}

	return media;
}
	
int main(){	
	int n, v[100100];
	cin >> n;
		
	for(int i=0;i<n;i++)
		cin >> v[i];

	cout << setprecision(2) << fixed;

	cout << media_vetor(n,v) << "\n";
	
	return 0;
}
	
