#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 1010

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int pd[MAX];
int treasure[MAX];
list<int> parents[MAX];
int n;
int qt;
int to;

int calc_pd(int i) {
    if (pd[i] == -1) {
        int max_treasure = 0;
        
        for(list<int>::iterator it = parents[i].begin(); it != parents[i].end(); it++) {
            max_treasure = max(max_treasure, calc_pd(*it));
        }

        pd[i] = treasure[i] + max_treasure;
    }

    return pd[i];
}

int main (void) {
    ios_base::sync_with_stdio(false);

    while (scanf("%d", &n) != EOF && n) {
        for (int i = 1; i <= n; i++) {
            parents[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            pd[i] = -1;
            scanf("%d %d", treasure+i, &qt);

            for (int j = 0; j < qt; j++) {
                scanf("%d", &to);          
                parents[to].push_back(i);
            }
        }

        for (int i = 1; i <= n; i++)
            calc_pd(i);

        printf("%d\n", *max_element(pd+1, pd+n+1));
    }

    return 0;
}

