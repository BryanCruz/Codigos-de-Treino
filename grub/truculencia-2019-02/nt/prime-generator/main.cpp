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

void print_primes(int m, int n) {
    bool primo;
    for (int i = max(2, m); i <= n; i++) {
        primo = true;

        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                primo = false;
                break;
            }
        }
        if (primo) printf("%d\n", i);
    }
}

int main (void) {
	ios_base::sync_with_stdio(false);

    int T, m, n;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &m, &n);

        print_primes(m, n);

        if (T > 0) printf("\n");
    }
	return 0;
}


