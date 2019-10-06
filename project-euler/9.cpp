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

int solve_c(int t, int a, int b) {
    return t - a - b;
}

int solve_b(int t, int a) {
    return (2 * a * t - t * t) / (-2 * t + 2 * a);
}

int main (void) {
    ios_base::sync_with_stdio(false);

    int target = 1000;
    int a=0, b=0, c=0;

    while (!(a*a + b*b == c*c && a + b + c == target)) {
        a = a + 1;
        b = solve_b(target, a);
        c = solve_c(target, a, b);
    }

    printf("%d\n", a*b*c);

    return 0;
}

