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

int palyndrome (int n) { 
  int reversed_n = 0;

  for (int x = n; x > 0; x /= 10)
    reversed_n = reversed_n * 10 + (x % 10);

  return n == reversed_n;
}

int main (void) {
	ios_base::sync_with_stdio(false);

  for(int guess = 999*999; guess >= 100*100; guess--) {
    if (!palyndrome(guess)) continue;

    for (int a = 100; a <= 999; a++) {
      if (guess % a != 0) continue;

      int b = guess / a;
      if (b >= 100 && b <= 999) {
        printf("%d = %d * %d\n", guess, a, b);

        guess = -1;
        break;
      }
    }
  }

	return 0;
}


