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

int main (void) {
	ios_base::sync_with_stdio(false);

    int n, k;
    scanf("%d %d", &n, &k);

    int steps = n-1 + min(n-k, k-1);
    int total = steps + 2*n+1;

    printf("%d\n", total);
	return 0;
}


