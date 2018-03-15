#include<iostream>

using namespace std;

int main(void){
	int p1, c1, p2, c2;
	cin >> p1 >> c1 >> p2 >> c2;

	int lado1 = p1*c1;
	int lado2 = p2*c2;

	if(lado1 > lado2){
		cout << "-1";
	}else if(lado2 > lado1){
		cout << "1";
	}else{
		cout << "0";
	}
	cout << "\n";
	return 0;
}
