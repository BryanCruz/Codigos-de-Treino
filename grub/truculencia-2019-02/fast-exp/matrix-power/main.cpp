#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAXM 50

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int MOD = 1000000007;

int M, N;

ll m[MAXM][MAXM];
ll p[MAXM][MAXM];
ll r[MAXM][MAXM];
ll s[MAXM][MAXM];

void copy_to_(ll a[MAXM][MAXM], ll b[MAXM][MAXM]) {
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            b[i][j] = a[i][j];
        }
    }
}

void mult(ll a[MAXM][MAXM], ll b[MAXM][MAXM], ll f[MAXM][MAXM]) {
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            f[i][j] = 0;
            for(int k = 0; k < M; k++){
                f[i][j] = (f[i][j]+((a[i][k]*b[k][j])%MOD))%MOD;
            }
        }
    }
}

void expo() {
    memset(r,0,sizeof r);

    for(int k = 0; k < M; k++) r[k][k] = 1;

    for(int n = N; n > 0; n=n>>1) {
        if(n%2) {
            copy_to_(r, s);
            mult(m, s, r);
        }

        if (n == 1) continue;

        copy_to_(m, p);
        mult(p, p, m);
    }
}

int main (void) {
	ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &M, &N);
        for (int i=0;i<M;i++) {
            for (int j=0;j<M;j++) scanf("%lld",&m[i][j]);     
        }
        expo();
        for (int i=0;i<M;i++) {
            printf("%d",r[i][0]);
            for(int j=1;j<M;j++)
                printf(" %lld",r[i][j]);
            printf("\n");
        }
    }

	return 0;
}
