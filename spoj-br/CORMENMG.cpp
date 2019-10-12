#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 6000

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct pd_struct {
    long long with, without;
};

int char_to_int(char c) {
    return c - '0';
}

int main (void) {
    ios_base::sync_with_stdio(false);

    char s[MAX];
    pd_struct pd[MAX];

    int i;
    while (true) {
        scanf("%s", s);
        if(s[0] == '0') break;

        pd[0].with = 0;
        pd[0].without = 1;

        for (i = 1; s[i] != '\0'; i++) {
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
                pd[i].with = pd[i-1].without;
            else pd[i].with = 0;

            if (s[i] == '0')
                pd[i].without = 0;
            else
                pd[i].without = pd[i-1].with + pd[i-1].without;
        }

        printf("%lld\n", pd[i-1].with + pd[i-1].without);
    }

    return 0;
}

