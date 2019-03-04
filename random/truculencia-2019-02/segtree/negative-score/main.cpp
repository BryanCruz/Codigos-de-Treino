#include<stdio.h>
#include<algorithm>

struct node {
    int v;
    int a;
    int b;
};

node st[300000]; // seg tree
int   v[200000]; // values
int  T, n, q;    // num_of_tests, num_of_eval, number_of_queries

void gen_st(int i, int a, int b) {
    st[i].a = a;
    st[i].b = b;

    if (a == b) {

       st[i].v = v[a];

    } else if (a < b) {
        int m = (a+b)/2;

        gen_st(2*i, a, m);
        gen_st(2*i+1, m+1, b);
        
        st[i].v = std::min(st[2*i].v, st[2*i+1].v);
        
    } else {
        printf("deu ruim aqui, b > a\n");
    }
}

int qa, qb;
int query(int i) {
    if (qb < st[i].a || qa > st[i].b) {
        return 1000000010;
    }

    if (st[i].a >= qa && st[i].b <= qb) {
        return st[i].v;
    }

    return std::min(query(2*i), query(2*i+1));
}

int main(void) {
    scanf("%d", &T);
    int a, b;       // interval to get min value

    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &n, &q);

        for (int i = 1; i <= n; i++) {
            scanf("%d", v+i);         
        }

        gen_st(1, 1, n);

        printf("Scenario #%d:\n", t);

        for (int i = 0; i < q; i++) {
            scanf("%d %d", &qa, &qb);

            printf("%d\n", query(1));
        }

    }

    return 0;
}
