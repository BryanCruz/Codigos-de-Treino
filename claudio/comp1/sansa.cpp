#include <bits/stdc++.h>

#define MAX 2000

using namespace std;

int heights[MAX];

bool verify(int a, int b, int k) {
    int count = 0;
    int i = 0;
    while (i <= b) {
        while (i <= b && heights[i] <= heights[i+1]) i++;
        if (i - a == 0) break;
    
        count++;
    
        a = i;
        while (i <= b && heights[i] >= heights[i+1]) i++;
        if (i - a == 0) break;
    }

    return count == k;
}

int main (void ) {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < MAX; i++) {
        scanf("%d", heights+i);
    }

    printf(verify(0, n-1, k) ? "beautiful\n" : "ugly\n");

    return 0;
}