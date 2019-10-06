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

ll vowal(char c) {
    switch (c) {
        case 'a':
            return 0;
        case 'e':
            return 1;
        case 'i':
            return 2;
        case 'o':
            return 3;
        case 'u':
            return 4;
        default:
            return -1;
    }
}

const ll all_vowals = 0b11111;
ll crivo[33][33];
ll dishes[100000+10];
ll count_[33];
char d[1010];

void run_test() {
    memset(dishes, 0, sizeof dishes);
    memset(count_, 0, sizeof count_);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", d);

        for (int j = 0; d[j] != '\0' && dishes[i] != all_vowals; j++) {
            dishes[i] |= (1 << vowal(d[j]));
        }

        count_[dishes[i]]++;
    }

    ll res = (((count_[31]-1)*count_[31])/2);
    for (int i = 0; i < 32; i++) {
        for(int j = i+1; j < 32; j++) {
            res += count_[i]*count_[j]*crivo[i][j];
        }
    }
    
    printf("%lld\n", res);
}

void build() {
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 32; j++) {
            crivo[i][j] = (i|j)==all_vowals;
        }
    }
}

int main (void) {
	ios_base::sync_with_stdio(false);

    build();

    int T;
    scanf("%d", &T);

    while(T--) {
        run_test();
    }

	return 0;
}


