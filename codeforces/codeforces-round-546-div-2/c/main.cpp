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

const int MAX = 5001;
int m, n;
int a[MAX][MAX];
int b[MAX][MAX];

void print_matrix() {
    printf("a:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("b:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

int main (void) {
	ios_base::sync_with_stdio(false);
    
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    bool can = true;

    for (int i = 0; i < n && can; i++) {
        for (int j = 0; j < m && can; j++) {
            if (a[i][j] == b[i][j]) {
                b[i][j] = 0;
            } else {
                can = false;

                int i2 = min(i+j, n-1);
                int j2 = max(i+j, n-1)-(n-1);
                for (int k = 0; i2-k >= 0 && j2+k < m && !can; k++) {
                    if (a[i][j] == b[i2-k][j2+k]) {
                        can = true;
                        b[i2-k][j2+k]=0;
                        swap(b[i][j], b[i2-k][j2+k]);
                    }
                }
            }
        }
    }

    if (can) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

	return 0;
}


