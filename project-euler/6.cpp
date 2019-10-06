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

  long long n = 100;

  long long diff = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      diff += i * j;
    }
  }
  diff *= 2;

  printf("%d\n", diff);

	return 0;
}


