#include<iostream>

using namespace std;

int main(void){
	char op;
	cin >> op;
	
	double a, b, result;
	cin >> a >> b;
	
	if(op == 'M'){
		result = a*b;
	}else{
		result = a/b;
	}

	cout.precision(2);
	cout.setf(ios::fixed);
	cout << result << "\n";

	return 0;
}
