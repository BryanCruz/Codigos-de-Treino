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

#define matrix vector<vector<ll>>

const ll MOD = 1000000007;

matrix operator *(matrix a, matrix b) {
    int lin = a.size();
    int col = b[0].size();
    int dia = b.size();

    matrix c(lin, vector<ll>(col));

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < dia; k++) {
                c[i][j] = (c[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }
        }
    }

    return c;
}

matrix id(ll n) {
    matrix a(n, vector<ll>(n));

    for(int i = 0; i < n; i++) {
        a[i][i] = 1;
    }

    return a;
}

matrix operator ^(matrix a, ll n) {
    if(n == 0) return id(a.size());

    matrix an2 = a^(n/2);
    matrix r = (an2*an2);

    if (n%2) {
        r = (r*a);
    }

    return r;
}

void print(matrix a) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[0].size(); j++) {
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

const matrix TRANSF = {{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}}; 
const matrix BASE = {{0},{1},{1},{1}}; 
ll calc(ll n) {
    if(n <= 1) return 0;
    
    return ((TRANSF^(n-1))*BASE)[0][0];
}

int main (void) {
	ios_base::sync_with_stdio(false);

    ll n;
    
    scanf("%lld", &n);

    printf("%lld\n", calc(n));

	return 0;
}


