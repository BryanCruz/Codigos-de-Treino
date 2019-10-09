#include <iostream>
#include <math.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 1000000

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n_collatz(long long x) {
  int c = 1;

  while (x != 1) {
    if (x % 2) x = 3*x + 1;
    else x /= 2;

    c++;
  }

  return c;
}

int main (void) {
    ios_base::sync_with_stdio(false);

    int max_n = 0;
    int max_i = -1;
    for (int i = 1; i <= MAX; i++) {
      int n = n_collatz(i);
      if (n > max_n) {
        max_n = n;
        max_i = i;
      }
    }

    cout << max_i << "\n";

    return 0;
}

