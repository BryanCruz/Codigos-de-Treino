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

ll d;

char n[19];

int main (void) {
	ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);

    while(T--) {
        scanf("%s %lld", n, &d);
    
        int  n_length = -1;

        while (n[++n_length] != '\0');

        int  i_min = -1;
        int  n_count = 0;

        while (i_min < n_length-1) {
            i_min++;
            int  i = i_min;
            char v_min = n[i];

            while(n[i] != '\0') {
                if (n[i] < v_min) {
                    v_min = n[i];
                    i_min = i;
                }
                i++;
            }

            if (v_min > ('0'+d)) break;
            printf("%c", v_min);
            n_count++;
        }

        while (n_count++ < n_length)
            printf("%d", d);

        printf("\n");
    }
	return 0;
}


