#include<iostream>

int house[5010];
int n, r;

int main(void){
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> r;
    
    // 1 == heater
    // heat pos - r + 1
    // heat pos + r - 1

    for(int i = 0; i < n; i++){
        std::cin >> house[i];
    }

    int j = r-1;
    int count = 0;
    int limInf = -1;
    int limSup = (n-1)+(r-1);
    while(j <= limSup){
        int i;
        for(i = 0; (j-i) > limInf && !house[j-i]; i++);

        if((j-i) > limInf){
            limInf = (j-i);
            j = (j-i) + 2*r-1;
            
            count++;
        }else{
            j = 4500;
            break;
        }
    }
    
    int result = -1;
    if(j != 4500){
        result = count;
    }
    
    std::cout << result << std::endl;
    
    return 0;
}
