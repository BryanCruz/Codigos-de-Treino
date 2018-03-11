//BVBP verdadeira
//BPBV verdadeira
//VBPB verdadeira
//VPB falsa
#include<iostream>

int main(void){
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;	
	
	if((a == c && b != d) || (a != c && b == d)){
		std::cout << "V";
	}else{
		std::cout << "F";
	}
	std::cout << "\n";
	return 0;
}
