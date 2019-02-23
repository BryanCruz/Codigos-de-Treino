#include <stdio.h>
#include <algorithm>

int _count = 0;
int c[100+1];

void print_height(int q, int i) {
    _count++;
    printf("%d", c[i]);
    if (_count < q) printf(" ");
    else printf("\n");
}

int main(void) {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", c+i);
    }

    std::sort(c, c+q);
    int max_diff = c[2]-c[0];

    int diff;
    for (int i = 1; i <= q-3; i++) {
        diff = c[i+2]-c[i];
        if (diff > max_diff) max_diff = diff;
    }
    
    int i = q%2? 1 : 0;
    for(; i < q; i+=2) {
        print_height(q, i);
    }

    i -= 1;
    for(; i >= 0; i-=2) {
        print_height(q, i);
    }

    return 0;
}
