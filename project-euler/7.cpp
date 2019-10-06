#include <bits/stdc++.h>

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

int main (void) {
	ios_base::sync_with_stdio(false);

  int sieve[MAX];
  memset(sieve, 0, sizeof(int) * MAX);


  int target = 10001;
  int i_prime = 0;
  int i;
  for (i = 2; i < MAX && i_prime < target; i++) {
    if (!sieve[i]) {
      i_prime++;
      
      for (int j = 2; j * i < MAX; j++) {
        sieve[j * i] = 1;
      }
    }
  }

  printf("%d\n", i_prime == target ? i-1 : -1);

	return 0;
}


