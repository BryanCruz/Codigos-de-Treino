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

const int MAX = 500000;

struct edge {
    int a, b;
};

int p[MAX+10];
edge es[MAX+10];

int n, m;

void print_queue() {
    for (int i = 0; i < n; i++) {
    }
}

int calc(int i_q, bool last) {
    vector<bool> can(i_q, false);

    for (int i = 0; i < i_q; i++) {
        for (int j = 0; j < m; j++) {
            if (es[j].a == p[i] && es[j].b == p[i_q]) {
                can[i] = true;
                break;
            }
        }
    }

    int c = 0;
    int i;
    for (i = i_q-1; i >= 0; i--) {
        if (can[i]) {
            c++;
            swap(p[i], p[i+1]);
        } else break;
    }

    if (i > 0) {
        
        if (last && calc(i, false) > 0 ) {
            c += calc(i+1, true);
        }
    }

    return c;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", p+i);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &(es[i].a), &(es[i].b));
    }

    printf("%d\n", calc(n-1, true));

	return 0;
}


