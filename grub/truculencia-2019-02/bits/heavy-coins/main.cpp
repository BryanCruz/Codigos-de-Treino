#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);


int bit(int mask, int b) {
    return (mask&(1<<b))!=0;
}

int main (void) {
	ios_base::sync_with_stdio(false);


    int T;

    scanf("%d", &T);

    while (T--) {
        int n, s;
        int p[10+10];

        memset(p, 0, sizeof p);

        scanf("%d %d", &n, &s);   

        for(int i = 0; i < n; i++) {
            scanf("%d", p+i);
        }
    
        int mask = (1 << (n+1))-1;
        int max_coins = 0;
        while (mask > 0) {
            int n_coins = 0;
            int total   = 0;
            n_coins = 0;
            for(int i = 0; i < n; i++) {
                if(bit(mask, i)) {
                    total += p[i];
                    n_coins++;
                }
            }

            int is_answer = 1;
            if(total >= s) {
                for(int i = 0; i < n && is_answer; i++) {
                    if (total-p[i] >= s && bit(mask, i)) is_answer=0; 
                }

                if (is_answer && n_coins > max_coins) max_coins = n_coins; 
            }

            mask--;
        }

        printf("%d\n", max_coins);
    }

	return 0;
}


