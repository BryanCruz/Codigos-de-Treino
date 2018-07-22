#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void){
	int t;
	cin >> t;

	while(t-- > 0){
		int n;
		cin >> n;

		int maiorAlice = 0, totalAlice = 0, maiorBob = 0, totalBob = 0;
		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;

			totalAlice += tmp;
			if(tmp > maiorAlice) maiorAlice = tmp;
		}

		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;

			totalBob += tmp;
			if(tmp > maiorBob) maiorBob = tmp;
		}

		totalAlice -= maiorAlice;
		totalBob   -= maiorBob;

		if(totalAlice < totalBob){
			cout << "Alice";
		}else if(totalAlice == totalBob){
			cout << "Draw";
		}else{
			cout << "Bob";
		}
		cout << endl;
	}
	return 0;
}
