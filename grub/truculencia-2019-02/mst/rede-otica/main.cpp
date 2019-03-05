#include <stdio.h>
#include <algorithm>

typedef struct edge edge;
struct edge {
    int u;
    int v;
    int p;
};


int n, m; // num vertices, num arestas
edge es[5000]; // arestas
int  vs[110];  // vertices
int wvs[110];  // tamanho do grupo de cada vertice
int mst[5000];


void init_uf() {
    for(int i = 1; i <= n; i++) {
        vs[i]  = i;
        wvs[i] = 1;
    }
}

int find(int v) {
    if(vs[v] == v) return v;

    vs[v] = find(vs[v]);

    return vs[v];
}

void swap(int* i, int* j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

void _union (int u, int v) {
    int p = find(u);
    int q = find(v);
    
    if(p == q) return;

    if(wvs[q] < wvs[p]) swap(&p, &q);

    vs[p]   = q;
    wvs[q] += wvs[p];
}

int comp(edge u, edge v) {
    return u.p < v.p;
}

int main(void) {

    int test_index = 1;

    scanf("%d %d", &n, &m);
    while(n != 0){
        if(test_index > 1) printf("\n");

        init_uf();
        
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &(es[i].u), &(es[i].v), &(es[i].p));
        }

        std::sort(es, es+m, comp);
        
        int j = 0;
        for(int i = 0; i < m; i++) {
            if(find(es[i].u) != find(es[i].v)) {
                mst[j++] = i;
                _union(es[i].u, es[i].v);
            }
        }

        printf("Teste %d\n", test_index++);
        for(int i = 0; i < j; i++) {
            int u = es[mst[i]].u;
            int v = es[mst[i]].v;

            if(u > v) swap(&u, &v);

                printf("%d %d\n", u, v);
        }   

        scanf("%d %d", &n, &m);
    }

    return 0;
}
