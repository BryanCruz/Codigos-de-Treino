#include<iostream>


int v[100010];
int c[100010];

void checar(int n){
	if(n == 0) return;

	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
		c[v[i]] = i;
	}

	int count;
	for(count = 1; count <= n && c[count] == v[count]; count++);

	if(count <= n) std::cout << "not ";
	std::cout << "ambiguous" << std::endl;
}

int main(void){
	std::ios_base::sync_with_stdio(false);
		
	int n = 42;

	while(n != 0){
		std::cin >> n;
		checar(n);
	}

	return 0;
}
