#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 2100

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main (void) {
    ios_base::sync_with_stdio(false);

    int knapsack[2][MAX];
    int items[MAX][2];

    int s, n;
    scanf("%d %d", &s, &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &items[i][0], &items[i][1]);
    }

    for (int j = 0; j <= s; j++) {
        knapsack[0][j] = 0;
    }

    int curr_row = 1;
    for (int i = 1; i <= n; i++, curr_row ^= 1) {
        for (int j = 0; j <= s; j++) {
            knapsack[curr_row][j] = knapsack[curr_row^1][j];

            if (j - items[i][0] >= 0) {
                knapsack[curr_row][j] = max(items[i][1] + knapsack[curr_row^1][j-items[i][0]], knapsack[curr_row][j]);
            }
        }

    }

    printf("%d\n", knapsack[n%2][s]);

    return 0;
}

