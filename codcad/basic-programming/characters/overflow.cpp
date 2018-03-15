#include<iostream>
	
using namespace std;

int main(void){
	int maior;
	cin >> maior;

	int n1, n2;
	char c;
	cin >> n1 >> c >> n2;
		
	int result;
	if(c == '*'){
		result = n1*n2;
	}else{
		result = n1+n2;
	}

	if(result > maior){
		cout << "OVERFLOW";
	}else{
		cout << "OK";
	}
	cout << "\n";
	return 0;
}
