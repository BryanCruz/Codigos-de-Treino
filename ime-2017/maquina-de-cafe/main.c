#include<stdio.h>
#include<limits.h>

int abs(int);

int main(void){
	int n = 3;
	int peopleQt[3];
	for(int i = 0; i < n; i++){
		scanf("%d", peopleQt + i);
	}

	int times[3];
	int minTime = INT_MAX;
	for(int floor = 0; floor < n; floor++){
		int actualTime = 0;
		for(int j = 0; j < n; j++){
			actualTime += 2*peopleQt[j]*(abs(j-floor));
		}

		if(actualTime < minTime) 
			minTime = actualTime;
	}

	printf("%d\n", minTime);

}

int abs(int x){
	return x > 0? x : -x;
}
