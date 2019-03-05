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

int n, k, x;

int *v;
int **m;
int *uf;
int *sz;
std::queue<int> next_;

int find(int i) {
    if (uf[i] != i) uf[i] = find(uf[i]);
    return uf[i];
}

void build() {
    int maxn = sizeof(int)*(n+10);
    uf = (int*) malloc(maxn);
    sz = (int*) malloc(maxn);
    
    for(int i = 1; i <= n; i++) {
        uf[i] = i;
    }

    memset(sz, 1, maxn);
}

int union_(int i, int j) {
    int p = find(i);
    int q = find(j);

    if (p == q) return -1;

    if (sz[p] > sz[q]) std::swap(p,q);
    uf[p] = q;
    sz[q] += sz[p];

    return j;
}

int index() {
    for(int i = 1; i <= n; i++) {
        if (v[i] == x) return i;
    }
    return -1;
}

int main (void) {
	ios_base::sync_with_stdio(false);
    
    scanf("%d", &n);

    int maxn = sizeof(int)*(n+10);
    v  = (int*) malloc(maxn);

    for(int i=1;i<=n;i++){
        scanf("%d", v+i);
    }

    scanf("%d", &k);

    int maxk = sizeof(int*)*(k+10);
    m  = (int**) malloc(maxk);
    for(int i=0;i<k+10;i++)
        m[i] = (int*) malloc(maxn);

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++) {
            scanf("%d", &m[i][j]);
        }
    }

    scanf("%d", &x);x=index();

    build();

    int ans = 0;
    int curr, tmp;
    if(find(1) == find(x)) ans = 1;
    next_.push(1);
    for(;ans == 0 && next_.size() > 0;){

        while(next_.size()>0){ 
            curr = next_.front();
            for(int i=1;i<=k;i++){
                tmp = union_(curr, m[i][curr]);
                if(tmp > 0) next_.push(tmp);
            }
            next_.pop();
        }
        if(find(1) == find(x)) ans = 1;
    }

    if (ans) {
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    free(v);
    free(uf);
    free(sz);
    for(int i=0;i<k+10;i++) free(m[i]);
    free(m);
	return 0;
}
