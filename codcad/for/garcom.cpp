#include<iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;

	int totalCoposQuebrados = 0;
	for(int i = 0; i < n; i++){
		int latas, copos;

		cin >> latas >> copos;

		if(latas > copos){
			totalCoposQuebrados += copos;
		}
	}
	
	cout << totalCoposQuebrados << "\n";
	return 0;
}
