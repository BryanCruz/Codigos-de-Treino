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


int n, m;
int a[300000+10], q;

int main (void) {
	ios_base::sync_with_stdio(false);


    ll total = 0;

    scanf("%d", &n);
    for(int i =0 ;i < n; i++){
        scanf("%d", a+i);
        total += a[i];
    }

    sort(a, a+n);

    scanf("%d", &m);
    for(int i =0 ;i < m; i++){
        scanf("%d", &q);
        printf("%lld\n", total - a[n-q]);
    }

	return 0;
}


