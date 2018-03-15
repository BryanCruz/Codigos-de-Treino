#include <iostream>
using namespace std; 
bool eh_primo(int x){ 	
		if(x <= 2) return true;
			bool primo = true;
				for(int i = 2; primo && i <= x/2; i++){
							primo = (x % i != 0);
								}
					
					return primo;
} 
	
int main(){ 	
		int x; 	
			cin>>x; 	
				if(eh_primo(x)){ 		
							cout<<"S"<<"\n"; 	
								}else{ 		
											cout<<"N"<<"\n"; 	
												} 
} 
	
