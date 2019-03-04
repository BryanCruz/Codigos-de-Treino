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

const int RM = 675;
const int MOD = 1000000007;

#define matrix vector<vector<ll>>

matrix operator *(matrix a, matrix b) {
    int lin = a.size();
    int col = b[0].size();
    int dia = b.size();

    matrix c(lin, vector<ll>(col));

    for(int i=0; i<lin;i++){
        for(int j=0; j<col;j++){
            for(int k=0; k<dia;k++){
                c[i][j] = (c[i][j] + (a[i][k]*b[k][j])%MOD)%MOD;
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
    if (n == 0) return id(a.size());

    matrix r = a^(n/2);
    r = r*r;

    if(n%2) r = r*a;

    return r;
}

int main (void) {
	ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    const matrix BASE({{6},{6}});
    const matrix TRANSF({{3,2},{2,2}});

    matrix result_matrix = (TRANSF^(n-1))*BASE;
    ll result = (result_matrix[0][0]+result_matrix[1][0])%MOD;
    cout << result << endl;

	return 0;
}


