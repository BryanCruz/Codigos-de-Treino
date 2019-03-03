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

int n, m, k;

struct student {
    int p, s;
};

student p[100+10];

int main (void) {
	ios_base::sync_with_stdio(false);

    scanf("%d %d %d", &n, &m, &k); //stu, scho, co

    for(int i = 1; i <= n; i++){
        scanf("%d", &(p[i].p));
    }

    for(int i = 1; i <= n; i++){
        scanf("%d", &(p[i].s));
    }

    int count_ = 0;
    int c;
    for(int i = 1; i <= k; i++){
        scanf("%d", &c);

        for(int j = 1; j <= n; j++) {
            if(p[c].s == p[j].s && p[c].p <= p[j].p && c != j) {
                count_++;
                p[c].p = -1;
                break;
            }
        }
    }

    printf("%d\n", count_);

	return 0;
}
