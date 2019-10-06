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

const int MAX = 2000;

int a[MAX+10];
int c[MAX+10];

int main (void) {
	ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);
    while(T--) {
        memset(a, 0, sizeof a);

        int n, k;

        scanf("%d %d", &n, &k);

        for (int i = 0; i < n; i++) scanf("%d", a+i);

        for (int l = 0; l < n; l++) {
            for (int r = n-1; r >= l; r--) {
                int m = ceil((1.0*k)/(r-l+1));

            }
        }
    }

	return 0;
}


