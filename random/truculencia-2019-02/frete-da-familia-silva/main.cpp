#include <stdio.h>
#include <algorithm>

struct edge {
    int u;
    int v;
    int p;
};

int n, m; // num vertices, num arestas

edge es[10100];
int  vs[1100];
int  ws[1100];

void init() {
    for(int i = 0; i < n; i++) {
        vs[i] = i;
        ws[i] = 1;
    }
}

int find(int v) {
    if(vs[v] == v) return v;

    vs[v] = find(vs[v]);

    return vs[v];
}

void swap(int* v, int* u) {
    int tmp = *v;
    *v      = *u;
    *u      = tmp;
}

void _union(int v, int u) {
    if(vs[v] == vs[u]) return;

    int p = find(v);
    int q = find(u);

    if(ws[p] > ws[q]) swap(&p, &q);

    vs[p] =  q;
    ws[q] += ws[p];
}

int comp(edge a, edge b) {
    return a.p < b.p;
}

int main(void) {

    scanf("%d %d", &n, &m);

    init();
    
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &es[i].u, &es[i].v, &es[i].p);
    }

    int total = 0;
    std::sort(es, es+m, comp);
    for(int i = 0; i < m; i++) {
        if(find(es[i].u) != find(es[i].v)) {
            total += es[i].p;
            _union(es[i].u, es[i].v);
        }
    }
    
    printf("%d\n", total);

    return 0;
}
