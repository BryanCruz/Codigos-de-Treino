#include <iostream>
#include <math.h>

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

long long binomial(int x) {
  ll r = 1;

  for (int i = 2*x-1; i > x; i-=2) {
    r *= i;
  }
  for (int i = 2*x; i > x; i-=2) {
    r *= 2;
  }
  for (int i = 2; i <= x / 2; i++){
    r /= i;
  }

  cout << r << endl;

  return r;
}

int main (void) {
    ios_base::sync_with_stdio(false);

    for (int n = 1; n <= 20; n++)
    cout << binomial(n) << "\n";

    return 0;
}

