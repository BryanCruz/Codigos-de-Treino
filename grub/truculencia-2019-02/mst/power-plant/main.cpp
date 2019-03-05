#include <stdio.h>
#include <algorithm>

int n, m, k; // vertices, arestas, power plants

struct edge {
    int u, v, c;
};

struct vertex {
    int i; // index of the group
    int p; // power plant, 1 if yes, 0 if no
    int w; // weigth of this vertex
};

edge    es[1048576];
vertex  vs[500];

void init() {
    for(int i = 1; i <= n; i++) {
        vs[i].i = i;
        vs[i].p = 0;
        vs[i].w = 1;
    }
}

int find(int v) {
    if (v == vs[v].i) return v;

    vs[v].i = find(vs[v].i);

    return vs[v].i;
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
    if (vs[p].w > vs[q].w) swap(&p, &q);

    vs[p].i  = q;
    vs[q].w += vs[p].w;
    vs[q].p  = vs[q].p || vs[p].p;
}

int comp(edge a, edge b) {
    return a.c < b.c;
}

int main(void) {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &n, &m, &k);

        init();

        int tmp;
        for(int i = 0; i < k; i++) {
            scanf("%d", &tmp);
            vs[tmp].p = 1;
        }

        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &es[i].u, &es[i].v, &es[i].c);
        }

        std::sort(es, es+m, comp);

        long long result = 0;
        for(int i = 0; i < m; i++) {
            int u = find(es[i].u);
            int v = find(es[i].v);

            if((vs[u].i != vs[v].i) && !(vs[u].p && vs[v].p)) {
                result += es[i].c;
                _union(es[i].u, es[i].v);
            }
        }
        printf("Case #%d: %d\n", t, result);
    }

    return 0;
}
