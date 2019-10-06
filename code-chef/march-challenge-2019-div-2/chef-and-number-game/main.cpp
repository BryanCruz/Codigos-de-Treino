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

int n;

int a;
int count_pos;
int count_neg;

int main (void) {
	ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);

        count_pos = 0;
        count_neg = 0;

        for(int i = 0; i <n; i++) {
            scanf("%d", &a);

            if (a < 0) count_neg++;
            else       count_pos++;
        }

        if (count_neg == 0) count_neg = count_pos;
        if (count_pos == 0) count_pos = count_neg;

        if (count_neg < count_pos) swap(count_neg, count_pos);

        printf("%d %d\n", count_neg, count_pos);
    }

	return 0;
}


