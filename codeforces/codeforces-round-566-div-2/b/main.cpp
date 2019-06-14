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

char m[510][510];

int main (void) {
	ios_base::sync_with_stdio(false);

  int h, w;
  scanf("%d %d\n", &h, &w);

  for (int i=1; i<=h; i++) {
    for (int j=1; j<=w; j++) {
      scanf("%c", &m[i][j]);
    }
    scanf("%*c");
  }

  for (int i = 0; i <= h; i++) {
    m[i][0] = '-';
    m[i][w+1] = '-';
  }
  for (int i = 0; i <= w; i++) {
    m[0][i] = '-';
    m[h+1][i] = '-';
  }

  bool found_center = false;

  for (int i = 1; i <= h && !found_center; i++) {
    for (int j = 1; j <= w && !found_center; j++) {
      if (m[i][j] == '*') {
        if (m[i-1][j] == '*' && m[i+1][j] == '*' && m[i][j-1] == '*' && m[i][j+1] == '*') {
          // center
          found_center = true;
          
          for (int k = i; k > 0 && m[k][j] == '*'; k--) {
            m[k][j] = '!';
          }

          for (int k = i+1; k <= h && m[k][j] == '*'; k++) {
            m[k][j] = '!';
          }

          for (int k = j-1; k > 0 && m[i][k] == '*'; k--) {
            m[i][k] = '!';
          }

          for (int k = j+1; k <= w && m[i][k] == '*'; k++) {
            m[i][k] = '!';
          }
        }
      }
    }
  }

  bool cross = true;

  if (!found_center) cross = false;

  for (int i = 1; i <= h && cross; i++) {
    for (int j = 1; j <= w && cross; j++) {
      if (m[i][j] == '*') {
        cross = false;
      }
    }
  }

  if ( cross )
    printf("YES\n");
  else
    printf("NO\n");

	return 0;
}


