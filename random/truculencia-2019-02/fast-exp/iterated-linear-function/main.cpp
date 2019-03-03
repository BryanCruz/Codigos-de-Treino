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
const ll MOD = 1000000007;

#define matrix vector<vector<ll>>

matrix operator *(matrix a, matrix b) {
    int lin = a.size();
    int col = b[0].size();
    int dia = b.size();

    matrix c(lin, vector<ll>(col));
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            for(int k = 0; k < dia; k++) {
                c[i][j] = (c[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }
        }
    }

    return c;
}

matrix id(ll n) {
    matrix m(n, vector<ll>(n));

    for(int i = 0; i < n; i++) {
        m[i][i] = 1;
    }

    return m;
}

matrix operator ^(matrix a, ll n) {
    if (n == 0) return id(a.size());

    matrix c = a^(n/2);
    c = c*c;

    if (n%2) {
        c = a*c;
    }

    return c;
}

int main (void) {
    ll A, B, n, x;

	ios_base::sync_with_stdio(false);

    scanf("%lld %lld %lld %lld", &A, &B, &n, &x);
    matrix base({{x}, {1}});
    matrix transf({{A, B}, {0, 1}});
    
    printf("%lld\n", ((transf^n)*base)[0][0]);
	return 0;
}


