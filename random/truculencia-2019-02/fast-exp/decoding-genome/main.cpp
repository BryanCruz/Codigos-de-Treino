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

ll n, m, k;
ll p[2704+10][2];

int char_to_int(char c) {
    if (c >= 'a' && c <= 'z') {
        return (int)(c-'a'+1-1);
    }

    return (int) (c - 'A'+27-1);
}

#define matrix vector<vector<ll>>

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

matrix id(int n) {
    matrix c = matrix(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        c[i][i] = 1;
    }
    return c;
}

matrix operator ^(matrix a, ll n) {
    matrix r = id(a.size());

    while(n>0) {
        if (n%2) {
            r = a*r;
        }
        a = a*a;

        n = n>>1;
    }

    return r;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    matrix transf(m, vector<ll>(m, 1));
    matrix base(m, vector<ll>(1, 1));
    char c1, c2;
    for(int i = 0; i < k; i++) {
        cin >> c1 >> c2;

        transf[char_to_int(c1)][char_to_int(c2)] = 0;
    }
    
    matrix result_matrix = (transf^(n-1))*base;
    ll result = 0;
    for(int i = 0; i < m; i++) {
        result = (result + result_matrix[i][0])%MOD;
    }
    cout << result << endl;

	return 0;
}
