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

const ll BASEFIB[3]       =  {2,1,0};
ll IDENTITY[3][3]   = {{1,0,0},{0,1,0},{0,0,1}};
ll BASETRANSF[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
const ll MOD = 1000000009;

ll n;
ll a[3][3];
ll b[3][3];
ll result[3][3];

void copy_to_(ll m1[3][3], ll m2[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            m2[i][j] = m1[i][j];
        }
    }
}

void mult(ll m1[3][3], ll m2[3][3], ll m3[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            m3[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                m3[i][j] = (m3[i][j]+(m1[i][k]*m2[k][j])%MOD)%MOD;
            }
        }
    }
}

void calc_fib(ll e) {
    copy_to_(IDENTITY, result);
    copy_to_(BASETRANSF, a);
    
    while(e > 0) {
        if(e%2) {
            mult(a, result, b);
            copy_to_(b, result);
        }

        mult(a, a, b);
        copy_to_(b, a);

        e = e>>1;
    }
}

void print_fib(ll f_i) {
    ll fib_value = 0;

    if(f_i <= 3) fib_value = BASEFIB[3-f_i];
    else{
        calc_fib(f_i-3);

        for(int i = 0; i < 3; i++) {
            fib_value = (fib_value+(result[0][i]*BASEFIB[i])%MOD)%MOD;
        }
    }

    printf("%lld\n", fib_value);
}

int main (void) {
	ios_base::sync_with_stdio(false);

    scanf("%lld", &n);

    while(n != 0) {
        print_fib(n);
        scanf("%lld", &n);
    }

	return 0;
}


