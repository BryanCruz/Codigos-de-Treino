#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 1048580

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int vs[MAX];
int n;

int main (void) {
    ios_base::sync_with_stdio(false);

    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", vs+i);
        }

        int total = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = 0;
            for (int j = i; j > 0 && tmp < 42; j--) {
                tmp += vs[j];
            }

            if (tmp == 42) {
                vs[i] = 42;
                total++;
            }
        }

        printf("%d\n", total);
    }
    

    return 0;
}

