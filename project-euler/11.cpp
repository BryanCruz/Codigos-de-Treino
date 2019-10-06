#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define s 20
#define ps 4

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main (void) {
    ios_base::sync_with_stdio(false);

    long long m[s][s];

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            cin >> m[i][j];
        }
    }

    long long max_product = -1;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            long long right = 1, down = 1, right_down = 1, left_down = 1;

            for (int k = 0; k < ps; k++) {
                if (j <= s - ps) {
                    right *= m[i][j+k];
                }

                if (i <= s - ps) {
                    down *= m[i+k][j];
                }

                if (i <= s - ps && j <= s - ps) {
                    right_down *= m[i+k][j+k];
                }

                if(i <= s - ps && j >= ps-1) {
                    left_down *= m[i+k][j-k];
                }
            }

            max_product = max(max(max(max(max_product, right), down), right_down), left_down);
        }
    }

    cout << max_product << "\n";

    return 0;
}

