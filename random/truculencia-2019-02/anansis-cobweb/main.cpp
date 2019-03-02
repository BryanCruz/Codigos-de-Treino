#include <bits/stdc++.h>

#define MAX 100000

int N, M, Q;

struct edge {
    int a, b;
};

int  uf[MAX+10];
int  sz[MAX+10];
edge es[MAX+10];
int estr[MAX+10];
std::vector<int> estr_sorted;
int  ans[MAX+10];

void build() {
    for (int i = 1; i <= N; i++) {
        uf[i] = i;
    }

    memset(sz, 1, sizeof sz);
}

int find(int i) {
    if (uf[i] != i) uf[i] = find(uf[i]);
    return uf[i];
}

void union_(int i, int j, int p, int q) {
   if (sz[p] > sz[q]) std::swap(p, q);

   uf[p] = q;
   sz[q] += sz[p];
}


int is_in(int a) {
    return std::binary_search(estr_sorted.begin(), estr_sorted.end(), a);
}

int main(void) {
    scanf("%d %d", &N, &M);

    build();

    int a, b;
    for(int i = 1; i <= M; i++) {
        scanf("%d %d", &a, &b);

        es[i].a = a;
        es[i].b = b;
    }

    scanf("%d", &Q);
    for(int i = 1; i <= Q; i++) {
        scanf("%d", &a);
        estr[i] = a;
    }
    estr_sorted = std::vector<int>(estr+1, estr+1+Q);
    std::sort(estr_sorted.begin(), estr_sorted.end());

    ans[Q] = N;
    for(int i=1; i<=M;i++) {
        if (is_in(i)) continue;

        a = find(es[i].a);
        b = find(es[i].b);

        if (a == b) continue;
        union_(es[i].a, es[i].b, a, b);
        ans[Q] -= 1;
    }

    for(int i=Q; i>1; i--) {
        a = find(es[estr[i]].a);
        b = find(es[estr[i]].b);

        ans[i-1] = ans[i];
        if (a == b) continue;
        union_(es[estr[i]].a, es[estr[i]].b, a, b);
        ans[i-1] -= 1;
    }

    printf("%d", ans[1]);
    for(int i=2; i<=Q; i++) printf(" %d", ans[i]);
    printf("\n");

    return 0;
}
