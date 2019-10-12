#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 60
#define MAX_C 1002

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int size[MAX];
int qtt[MAX];
long long pd[MAX][MAX_C];
int f;

long long calc(int n, int i) {
    if (i >= f) return 0;
    if (pd[i][n] != -1) return pd[i][n];

    pd[i][n] = max(n - size[i] >= 0 ? qtt[i] + calc(n-size[i], i+1) : 0, calc(n, i+1));

    return pd[i][n];
}

int main (void) {
    ios_base::sync_with_stdio(false);

    int n;
    long long t = 0;
    while(scanf("%d %d", &n, &f) && (n || f)) {
        for (int i = 0; i < f; i++) {
            for (int j = 0; j <= n; j++) {
                pd[i][j] = -1;
            }

            scanf("%d %d", size+i, qtt+i);
        }

        printf("Teste %lld\n%lld\n\n", ++t, calc(n, 0));
    }

    return 0;
}

