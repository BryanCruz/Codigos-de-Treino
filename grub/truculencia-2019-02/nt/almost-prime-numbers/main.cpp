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

const ll MAX = 1000000000000;
const ll MAX2 = 1000000;
ll R, L;

vector<bool> crivo;
list<ll>    almost_primes;

void init() {
    crivo.resize(MAX2+10, false);

    for (ll i = 2; i <= MAX2; i++) {
        if (!crivo[i]) {
            for(ll j = 0; j*i+i*i <= MAX2; j++) {
                crivo[j*i+i*i] = true;
            }
        }
    }

    for (ll i = 2; i <= MAX2; i++) {
        if (!crivo[i]) {
            for (ll j = i*i; j <= MAX; j*=i) {
                almost_primes.push_back(j);
            }
        }
    }

    almost_primes.sort();
}

ll get_(ll i, ll j) {
    ll c = 0; 
    for (list<ll>::iterator it = almost_primes.begin(); *it <= j; it++) {
        if (*it < i) continue;
        c++;   
    } 
    return c;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    init();

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &L, &R);
        printf("%lld\n", get_(L, R));
    }

	return 0;
}
