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

const int MAX = 2*50010;

#define s 2
#define e 1

int size = 0;

char l[2*MAX];

int main (void) {
	ios_base::sync_with_stdio(false);

    long long T;
    scanf("%lld", &T);

    for(long long t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        scanf("%d", &size);
        scanf("%s", l);

        
        for (int i = 0; l[i] != '\0'; i++) {
            if (l[i] == 'S') {
                printf("E");
            } else {
                printf("S");
            }
        }
        printf("\n");
    }
	return 0;
}


