#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 775147
#define N 600851475143

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main (void) {
	ios_base::sync_with_stdio(false);

  int sieve[MAX];
  memset(sieve, 0, sizeof(int)*MAX);

  int max_prime = 0;
  for (int i = 2; i < MAX; i++) {
    if(!sieve[i]) {
      if (N % i == 0)
        max_prime = i;

      for (int j = 2; j * i < MAX; j++) {
        sieve[j * i] = 1;
      }
    }
  }

  printf("%d\n", max_prime);

	return 0;
}
