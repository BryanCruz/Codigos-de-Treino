#include <bits/stdc++.h>

#define MAX 2000

using namespace std;

int main (void ) {
    int n1, n2;
    int v[20];

    while (true) {
        scanf("%d %d", &n1, &n2);
        if (n1 == 0 && n2 == 0) break;

        int v_i = 20;
        int r = n1 + n2;
        
        while (r > 0) {
            if (r % 10) {
               v[v_i--] = r%10;
            }

            r /= 10;
        }

        for (int i = v_i+1; i <= 20; i++) {
            printf("%d", v[i]);
        }
        printf("\n");
    }
    return 0;
}