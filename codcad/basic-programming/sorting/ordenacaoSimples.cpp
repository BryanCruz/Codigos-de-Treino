#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	int n;
	cin >> n;

	int v[n];
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	sort(v, v+n);

	for(int i = 0; i < n; i++){
		if(i != 0) cout << " ";
		cout << v[i];
	}
	cout << endl;
	return 0;
}
