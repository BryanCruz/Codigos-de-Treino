#include <stdio.h>

int w1, h1, w2, h2;

int main(void) {
    scanf("%d %d %d %d", &w1, &h1, &w2, &h2);   

    int l = h1+h2+2;
    int b = w2+1;
    int t = w1+1;
    int r = h1+h2+(w1-w2);

    printf("%d\n", l+b+t+r);

    return 0;
}
