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

    int n; //n of chapters
    scanf("%d", &n);

    vector<int> chapters;

    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d %*d", &tmp);
        chapters.push_back(tmp);
    }

    scanf("%d", &tmp);

    vector<int>::iterator it = upper_bound(chapters.begin(), chapters.end(), tmp);
    printf("%d\n", n+1-(it-chapters.begin()));

	return 0;
}
