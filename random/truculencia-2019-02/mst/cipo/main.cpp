#include <stdio.h>
#include <algorithm>

int n, m; // vertices, arestas

struct edge {
    int u, v, c;
};

edge es[2000100];
int  vs[1100];
int  ws[1100];

void init() {
    for(int i = 1; i <= n; i++) {
        vs[i] = i;
        ws[i] = 1;
    }
}

int find(int v) {
    if (v == vs[v]) return v;

    vs[v] = find(vs[v]);

    return vs[v];
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a      = *b;
    *b      = tmp;
}

void _union(int u, int v) {
    int p = find(u);
    int q = find(v);

    if (p == q) return;
    if (ws[p] > ws[q]) swap(&p, &q);

    vs[p]  = q;
    ws[q] += ws[p];
}

int comp(edge a, edge b) {
    return a.c < b.c;
}

int main(void) {
    int instance = 0;

    while(scanf("%d %d", &n, &m) != EOF) {
        init();

        instance++;

        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &es[i].u, &es[i].v, &es[i].c);
        }

        std::sort(es, es+m, comp);

        long long result = 0;
        for(int i = 0; i < m; i++) {
            if(find(es[i].u) != find(es[i].v)) {
                result += es[i].c;
                _union(es[i].u, es[i].v);
            }
        }
        printf("Instancia %d\n", instance);
        printf("%d\n\n", result);
    }

    return 0;
}
