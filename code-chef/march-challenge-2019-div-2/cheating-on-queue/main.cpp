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
struct as {
    int a, i;
};
as a[MAX+10];
int idx[MAX+10];
int n;
ll k;

ll calc(int p) {
    ll result = 0;

    for (int i = 1; i <= n && result<=k; i++) {
        result += (a[i].i >= p ? a[i].a/(a[i].i-p+1) : 0);
    }

    return result;
}

int comp(as a1, as a2) {
    return a1.a > a2.a;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &n, &k);

        for(int i = 1; i <= n; i++){
            scanf("%d", &(a[i].a));
            a[i].i = i;
        }

        sort(a+1, a+n+1, comp);

        ll v;
        int l = 1, r = n;
        int i = -1;

        while (l <= r) {
            int m = (l+r)/2;
            v = calc(m);

            if (k - v >= 0) {
                r = m-1;

                if (i == -1 || m < i) i = m;
            } else {
                v = calc(l);
                if (k-v >= 0) {i = l;break;}

                l = l+1;
            }
        }

        if (i == -1) i = n+1;
        
        printf("%d\n", i);
    }

	return 0;
}


