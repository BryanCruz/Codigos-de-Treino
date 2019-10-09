#include <iostream>
#include <math.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 500

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main (void) {
    ios_base::sync_with_stdio(false);

    int n[MAX];
    memset(n, 0, sizeof(int)*MAX);

    n[0] = 1;
    int p = 1000;
    int max_j = 1;

    for(int i = 1; i <= p; i++) {
      for (int j = 0; j < max_j; j++) {
        n[j] *= 2;
      }

      for (int j = 0; j < max_j; j++) {
        n[j+1] += n[j] / 10;
        n[j] %= 10;
      }
      if(n[max_j] > 0) max_j++;
    }

    int sum = 0;
    for(int i = 0; i < max_j; i++) {
      cout << n[i] << " ";
      sum += n[i];
    }

    cout << sum << "\n";

    return 0;
}

