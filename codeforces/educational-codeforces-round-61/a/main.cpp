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

int main (void) {
	ios_base::sync_with_stdio(false);

    int t1, t2, t3, t4; // ((, (), )(, ))
    scanf("%d %d %d %d", &t1, &t2, &t3, &t4);

    int result = (t1 == t4 && t1 >= 0);
    
    printf("%d\n", result ? 1 : 0);

	return 0;
}


