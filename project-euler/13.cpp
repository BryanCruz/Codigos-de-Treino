#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX_RESULT 10000
#define MAX_INPUT_ 50
#define N 100

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main (void) {
    ios_base::sync_with_stdio(false);

    string s;

    char nums[N][MAX_INPUT_];
    int result[MAX_RESULT];

    memset(result, 0, sizeof(int)*MAX_RESULT);

    for (int i = 0; i < 100; i++) {
        scanf("%s", nums[i]);

        for (int j = MAX_INPUT_-1; j >= 0; j--) {
            result[MAX_INPUT_-j-1] += nums[i][j] - '0';
        }
    }

    int r = 0;
    int i;
    for (i = 0; r != 0 || i < MAX_INPUT_; i++) {
        result[i] += r;

        r = result[i] / 10;
        result[i] %= 10;
    }

    i--;
    for (int j = 0; j < 10; j++) {
        printf("%c", '0' + result[i-j]);
    }
    printf("\n");

    return 0;
}

