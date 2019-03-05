#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 1000000000
#define matrix vector<vector<ll>>

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const ll MOD = 1000000007;

matrix operator *(matrix m1, matrix m2) {
    int l  = (int)m1.size();
    int c  = (int)m2[0].size();
    int cl = (int)m2.size();
    matrix m3(l, vector<ll>(c));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < cl; k++) {
                m3[i][j] = (m3[i][j] + (m1[i][k]*m2[k][j])%MOD)%MOD;
            }
        }
    }

    return m3;
}

matrix id(int n) {
    matrix m(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        m[i][i] = 1;
    }

    return m;
}

matrix operator ^(matrix m, int e) {
    int s = m.size();

    matrix b = m;
    m        = id(s);

    while (e > 0) {
        if (e%2) {
            m = m*b;
        }
            
        b = b*b;
        e = e>>1;
    }

    return m;
}

const matrix BASE  = {{1},{1},{0}};
const matrix TRANS = {{1,1,1},{0,1,1},{0,1,0}}; 
ll calc_fib(int n) {
    if(n == -1) return 0;
    if(n == 0)  return 0;
    if(n == 1)  return 1;

    return ((TRANS^(n-1))*BASE)[0][0];
}

ll calc_fib_sum(int n, int m) {
    return (calc_fib(m)-calc_fib(n-1)+MOD)%MOD;   
}

int main (void) {
	ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);

    int m, n;

    for(int i = 0; i < T; i++) {
        scanf("%d %d", &n, &m);

        printf("%lld\n", calc_fib_sum(n, m));
    }

	return 0;
}


