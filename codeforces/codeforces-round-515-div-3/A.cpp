#include<iostream>

int main(void){
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    int L, v, l, r;
    while(n--){
        std::cin >> L >> v >> l >> r;
    
        // initial count
        int count = L / v;

        // remove the ones behind the train
    
        int i, j;
        i = (l - l%v) + ((l % v == 0) ? 0 : v);
        j = (r - r%v);

        int behind = (j >= i) ? ((j-i)/v)+1 : 0;
    
        count -= behind;
        std::cout << count << std::endl;
    }

    return 0;
}
