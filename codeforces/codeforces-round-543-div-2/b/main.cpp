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
int a[1000+10];
int s[1000*1000+10];

int main (void) {
	ios_base::sync_with_stdio(false);

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }

    memset(s, 0, sizeof s);
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            s[a[i]+a[j]]++;
        }
    }

    int max_ = 0;
    for(int i = 0; i < 1000*1000+10; i++) {
        if(s[i] > max_) max_ = s[i];
    }

    printf("%d\n", max_);

	return 0;
}


