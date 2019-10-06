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

const int MAX = 10e5;
int a[MAX+10];
int n;
ll k;

ll calc(int p) {
    ll result = 0;

    for (int i = 1; i <= n-p+1; i++)
        result += a[p+i-1]/i;

    return result;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &n, &k);

        for(int i = 1; i <= n; i++)
            scanf("%d", a+i);

        ll v;
        int min_i = -1;

        for (int i = 1; i <= n; i++) {
            v = calc(i);

            if (k-v >= 0) {
                min_i = i;
                break;
            }
        }

        if (min_i == -1) min_i = n+1;
        
        printf("%d\n", min_i);
    }

	return 0;
}


