#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	int n;
   	int poquemaos[3];
	cin >> n;
    for(int i = 0; i < 3; i++){
		cin >> poquemaos[i];
	}

	sort(poquemaos, poquemaos+3);

	int i = 0;
	while(i < 3 && n >= poquemaos[i]){
		n -= poquemaos[i];
		i++;
	}

	cout << i << endl;
	return 0;
}
