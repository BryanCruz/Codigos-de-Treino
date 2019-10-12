#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 10010

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main (void) {
    ios_base::sync_with_stdio(false);

    int n;
    int v[MAX];
    int pd[MAX];
    v[0] = 0;
    pd[0] = 0;

    while(scanf("%d", &n) != EOF && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", v + i);
        }

        for (int i = 1; i <= n; i++) {
            pd[i] = max(v[i], pd[i-1]+v[i]);
        }

        int max_pd = *max_element(pd, pd + n + 1);

        if (max_pd > 0) {
            printf("The maximum winning streak is %d.\n", max_pd);
        } else {
            printf("Losing streak.\n");
        }
    }

    return 0;
}

