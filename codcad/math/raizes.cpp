#include<iostream>
#include<cmath>

using namespace std;

int main(void){
	int n;
	cin >> n;
		
	cout.precision(4);
	cout.setf(ios::fixed);
	
	for(int i = 0; i < n; i++){
		double num;
		cin >> num;

		double result = pow(num, 1.0/2);
		cout << result << endl;
	}
	return 0;
}
