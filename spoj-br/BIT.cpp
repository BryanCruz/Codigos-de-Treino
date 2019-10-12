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

    int v;
    int t = 0;

    int notas[] = {50, 10, 5, 1};
    int cedulas[4];

    while (scanf("%d", &v) != EOF && v != 0) {
        for (int i = 0; i < 4; i++) {
            cedulas[i] = v / notas[i];
            v -= notas[i] * cedulas[i];
        }

        printf("Teste %d\n", ++t);
        printf("%d %d %d %d\n", cedulas[0], cedulas[1], cedulas[2], cedulas[3]);
    }


    return 0;
}

