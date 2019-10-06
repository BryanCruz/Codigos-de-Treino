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

int evenly_divisible(int max_n, int value) {
  for (int i = 2; i <= max_n; i++)
    if (value % i != 0) return 0;

  return 1;
}

int main (void) {
	ios_base::sync_with_stdio(false);

  int guess = 20;
  while(!evenly_divisible(20, guess)) guess++;

  printf("%d\n", guess);

	return 0;
}


