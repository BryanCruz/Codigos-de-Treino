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

long long n_factors(long long n) {
    int c = 0;

    long long i;
    for (i = 1; i * i < n; i++) {
        if (!(n % i)) c++;
    }

    return i*i == n ? c*2 + 1 : c*2;
}

int triangle(int x) {
    return (x*(x+1))/2;
}

int main (void) {
    ios_base::sync_with_stdio(false);

    long long n = 0;
    int i;
    for (i = 1; i < 10e6 && n < 500; i++) {
        n = n_factors(triangle(i));
    }
    
    cout << triangle(i-1) << "\n";
    

    return 0;
}

