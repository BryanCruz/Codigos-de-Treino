#include<iostream>

int desloc[200010];

int main(void){
    std::ios_base::sync_with_stdio(false);

    int n;

    std::cin >> n;
    char q;
    int id;

	int countL = -1;
	int countR = 0;
    int count  = 0;

    while(n--){
	    std::cin >> q >> id;

	    if(q == 'L'){
            desloc[id] = countL;
            countL--;
            count++;
        }else if(q == 'R'){
            desloc[id] = countR;
            countR++;
		    count++;
	    }else{
            int result;
            if(desloc[id] < 0){
                result = desloc[id] - (countL + 1);
            }else{
                result = (countR-1) - desloc[id];
            }

            std::cout << std::min(result, count-result-1) << std::endl;
        }
	}
    return 0;
}
