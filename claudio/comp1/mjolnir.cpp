#include <bits/stdc++.h>

using namespace std;

int main (void ) {
    int n;
    char name[10000];

    scanf("%d", &n);

    while (n--) {
        scanf("%s %*d", name);

        if (strcmp(name, "Thor")) printf("N\n");
        else printf("Y\n");
    }

    return 0;
}