#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void){
	long long a, b;
	cin >> a >> b;

	int result = 1;
	for(long long i = b; result > 0 && i > a; i--){
		result *= i % 10;
		result = result % 10;
	}

	cout << result << endl;
	return 0;
}
