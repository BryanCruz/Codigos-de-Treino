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

#define MAX 200000

struct lt { 
    ll c;
    ll v;
    ll t = 0;
};

lt a[MAX+10];

int n, t, ct;

int calc_tf(int ct) {
    int t_min = MAX+100;
    int i_min = -1;
    for(int i = 1; i <= n; i++) {
        a[i].t = a[i].t + a[i].c/a[i].v+1;

        if(a[i].t == t_min && t_min == ct+1) return -1;
        if(a[i].t < t_min) t_min = a[i].t, i_min=i;
    }

    return i_min;
}

int main (void) {
	ios_base::sync_with_stdio(false);
    
    scanf("%d %1d", &n, &t);
    ct = 0;

    for(int i = 1; i <= n; i++)
        scanf("%lld", &(lt[i].c]));

    for(int i = 1; i <= n; i++)
        scanf("%lld", &(lt[i].v]));

    int aaa[2];

    aaa = calc_tf();   

    if(aaa < 0) printf("-1\n");

    lt[aaa].t -= (:q) 
    
	return 0;
}


