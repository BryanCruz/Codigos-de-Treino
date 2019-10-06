#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 4e6

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main (void) {
	ios_base::sync_with_stdio(false);

  long long a = 1, b = 2, sum_even = 0;

  while (b < MAX) {
    if (b % 2 == 0)
      sum_even += b;

    long long c = a + b;
    a = b;
    b = c;
  }

  printf("%lld\n", sum_even);

	return 0;
}


