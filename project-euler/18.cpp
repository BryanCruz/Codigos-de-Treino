#include <iostream>
#include <math.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 50000

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int line(int n) {
  return ( n * (n - 1 ) ) / 2;
}

int main (void) {
    ios_base::sync_with_stdio(false);
  
    int t[MAX];
    memset(t, 0, sizeof(int)*MAX);

    int j = 0;
    int l = 1;
    while (scanf("%d", t + line(l) + j) != EOF) {
      j++;

      if (j == l) {
        l++;
        j = 0;
      }
    }

    for (int i = l-2; i > 0; i--) {
      for (j = 0; j < i; j++) {
        t[line(i)+j] += max(t[line(i+1)+j],t[line(i+1)+j+1]);
      }
    }

    cout << t[0] << "\n";

    return 0;
}

