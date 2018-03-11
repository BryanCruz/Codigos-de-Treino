#include<iostream>

using namespace std;

int main(void){
	int victsC, drawsC, goalsC;
	int victsF, drawsF, goalsF;

	cin >> victsC >> drawsC >> goalsC;
	cin >> victsF >> drawsF >> goalsF;

	int totalC = victsC*3 + drawsC*1;
	int totalF = victsF*3 + drawsF*1;


	if(totalC > totalF){
		cout << "C";
	}else if(totalF > totalC){
		cout << "F";
	}else if(goalsC > goalsF){
		cout << "C";
	}else if(goalsF > goalsC){
		cout << "F";
	}else{
		cout << "=";
	}
	cout << "\n";
	return 0;
}
