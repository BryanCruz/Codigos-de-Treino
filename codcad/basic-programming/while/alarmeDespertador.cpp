#include<iostream>

using namespace std;

int main(void){
	int h1, m1, h2, m2;
	cin >> h1 >> m1 >> h2 >> m2;
	while(h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0){
		int totalHoras = h2 - h1;
		if(totalHoras < 0){
			totalHoras += 24;
		}

		int totalMinutos = m2-m1 + totalHoras*60;
		if(totalMinutos < 0){
			totalMinutos += 24*60;
		}

		cout << totalMinutos << "\n";
		cin >> h1 >> m1 >> h2 >> m2;
	}

	return 0;
}
