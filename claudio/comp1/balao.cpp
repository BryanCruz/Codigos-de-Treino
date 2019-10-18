#include <bits/stdc++.h>

#define MAX 2000

using namespace std;


int main (void ) {
    int caixa[10][10];


    while(true){
        int l, c, p;
        memset(caixa, 0, sizeof caixa);
        scanf("%d %d %d", &l, &c, &p);

        if (l == 0 && c == 0 && p == 0) break;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &caixa[i][j]);
            }
        }
    
        bool r = true;
        int i;
        p--;
        for (i = 0; i < l; i++) {
            int orig_p = p;
 
            if(caixa[i][p]) {
                r = false;
                i--;
                break;
            }


            for (int j = p-1; j >= 0; j--) {
                if (caixa[i][j] > 0) {
                    p += caixa[i][j];
                    break;
                }
            }

            for (int j = orig_p+1; j < c; j++) {
                if (caixa[i][j] > 0) {
                    p -= caixa[i][j];
                    break;
                }
            }

            int min_left = p < orig_p ? p : orig_p;
            int max_right = p > orig_p  ? p : orig_p;

            for (int j = min_left; j <= max_right; j++) {
                if (caixa[i][j] > 0) {
                    r = false;
                    break;
                }
            }

            if (!r) break;
        }

        if (r) {
            printf("OUT %d\n", p);
        } else {
            printf("BOOM %d %d\n", i+1, p);
        }
    }

    return 0;
}