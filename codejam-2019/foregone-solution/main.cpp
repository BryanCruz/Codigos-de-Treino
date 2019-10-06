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

    long long T;
    scanf("%lld", &T);

    for(int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        char n[110];

        scanf("%s", n);

        int i;

        for (i = 0; n[i] != '\0'; i++) {
            char c = n[i];

            if (c == '4') {
                printf("3");
            }
            else {
                printf("%c", c);
            }
        }
        printf(" ");

        for (i = 0; n[i] != '4'; i++);

        for (; n[i] != '\0'; i++) {
            char c = n[i];

            if (c == '4') {
                printf("1");
            }
            else {
                printf("0");
            }
        }

        printf("\n");
    }
	return 0;
}


