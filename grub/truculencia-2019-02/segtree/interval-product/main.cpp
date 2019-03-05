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

#define MAX 100000

int n, k;
int st[4*MAX+10];
int  vs[MAX+10];
char q;

int l, r;


int signal_(int n) {
    if (n == 0) return 0;
    return n/abs(n);
}

int avg(int a, int b) {
    return (a+b)/2;
}

void print_tree(int i, int cl, int cr) {
    printf("(i: %d, cl: %d, cr: %d) %d\n", i, cl, cr, st[i]);

    if(cl >= cr) return;
    int m = avg(cl,cr);
    print_tree(i<<1,cl,m);
    print_tree(i<<1|1,m+1,cr);
}

void build(int i, int cl, int cr) {
    if (cl == cr) {
        st[i] = signal_(vs[cl]);
        return;
    }

    int m = avg(cl,cr);
    build(i<<1,cl,m);
    build(i<<1|1,m+1,cr);
    st[i]=st[i<<1]*st[i<<1|1];
}

void print(int n) {
    if (n > 0)
        printf("+");
    else if (n < 0)
        printf("-");
    else
        printf("0");
}

int v;

int set_(int i, int cl, int cr) {
    if (cl > cr)            return 1;
    if (cl > r || cr < l)   return st[i];
    if (cl >= l && cr <= r) return st[i] = signal_(v);

    int m = avg(cl,cr);
    int r1 = set_(i<<1,cl,m);
    int r2 = set_(i<<1|1,m+1,cr);
    return st[i]=r1*r2;
}

int get_(int i, int cl, int cr) {
    if(cl > cr)             return 1;
    if(cl > r || cr < l)    return 1;
    if(cl >= l && cr <= r)  return st[i];

    int m  = avg(cl,cr);
    int r1 = get_(i<<1,cl,m);
    int r2 = 1;
    if (r1) {
        r2 = get_(i<<1|1,m+1,cr);
    }

    return r1*r2;
}

int main(void) {
	ios_base::sync_with_stdio(false);

    while(scanf("%d %d", &n, &k) != EOF) {
        for(int i = 1; i <= n; i++)
            scanf("%d", vs+i);

        build(1, 1, n);

        for(int i = 0; i < k; i++) {
            scanf("%*c%c %d %d", &q, &l, &r); 
            if(q == 'P') print(get_(1, 1, n));
            else {
                v = r;
                r = l;
                set_(1, 1, n);
            }
        }

        printf("\n");
    }

	return 0;
}
