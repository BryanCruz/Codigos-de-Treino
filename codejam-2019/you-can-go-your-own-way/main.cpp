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

const int MAX = 1000;

#define s 2
#define e 1

int a[MAX][MAX];

int size = 0;

char l[2*MAX];

void init_() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a[i][j] = s+e;

            if (i == size-1) {
                a[i][j] -= s;
            } 
            if (j == size-1) {
                a[i][j] -= e;
            }
        }
    }

    int i = 0;
    int j = 0;
    for(int step = 0; l[step] != '\0'; step++) {
        if (l[step] == 'S') {
            a[i][j] -= s;
            i++;
        } else {
            a[i][j] -= e;
            j++;
        }
    }
}

bool dp (int i, int j) {
    if (i == size-1 && j == size-1) {
        return true;
    }   

    if (a[i][j] == 0) {
        return false;
    }

    bool tmp;
    if (a[i][j] == e) {
        tmp = dp(i, j+1);

        if (tmp) return true;

        a[i][j] = 0;
        return false;
    }

    if (a[i][j] == s) {
        tmp = dp(i+1, j);

        if (tmp) return true;

        a[i][j] = 0;
        return false;
    }

    tmp = dp(i, j+1);
    if (tmp) {
        a[i][j] = e;
        return true;
    }

    tmp = dp(i+1, j);
    if (tmp) {
        a[i][j] = s;
        return true;
    }
    
    a[i][j] = 0;
    return false;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    long long T;
    scanf("%lld", &T);

    for(long long t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        scanf("%d", &size);
        scanf("%s", l);

        init_();

        dp(0, 0);

        int i = 0;
        int j = 0;
        
        while(i != size-1 || j != size-1) {
            if (a[i][j] == e) {
                printf("E");
                j++;
            } else {
                printf("S");
                i++;
            }
        }
        printf("\n");
    }

	return 0;
}


