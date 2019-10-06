#include <stdio.h>
#include <queue>

using namespace std;

const int MAX = 10e5;
struct as {
    int a, i;
};
as a[MAX+10];
int n;
int k;
int result;

queue<int> update[MAX+10];

int calc(int p) {
    if (p > n) return p;

    while (!update[p].empty()) {
        int i = update[p].front();
        result += ((i-p+1)>0 ? a[i].a/(i-p+1) : 0)- (a[i].i > 0 ? a[i].a/a[i].i : 0);
        a[i].i = (p+i-1);
        update[p].pop();
    }

    if (result <= k) return p;
    else return calc(p+1);
}

void build() {
    int diff;
    int curr;
    for(int i = 1; i <= n; i++) {
        update[i+1].push(i);
        diff = -1;
        for (int j = i, it=i; j > 0; j--,it--) {
            curr = a[i].a / j;
            if (curr != diff) {
                update[it].push(i);
                diff = curr;
            }
        }
    }
}

int main (void) {
    int T;
    scanf("%d", &T);
    a[0].a = 0;
    a[0].i = 1;

    while(T--) {
        scanf("%d %d", &n, &k);
        result = 0;

        for(int i = 1; i <= n; i++){
            scanf("%d", &(a[i].a));
            a[i].i = 0;
        }

        build();

        printf("%d\n", calc(1));
    }

    return 0;
}
