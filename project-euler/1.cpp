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

int multiple_of_3(int x) {
  return x % 3 == 0;
}

int multiple_of_5(int x) {
  return x % 5 == 0;
}

int multiple_of_3_or_5(int x) {
  return multiple_of_3(x) || multiple_of_5(x);
}

int sum_if(int (*func) (int), int n) {
  int sum = 0;

  for(int i = 0; i < n; i++) {
    if(func(i)) {
      sum += i;
    }
  }

  return sum;
}

int main (void) {
	ios_base::sync_with_stdio(false);
  
  int n;
  scanf("%d", &n);

  printf("%d\n", sum_if(multiple_of_3_or_5, n));

	return 0;
}


