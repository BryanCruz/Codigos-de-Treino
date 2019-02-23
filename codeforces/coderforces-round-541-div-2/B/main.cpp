#include <stdio.h>
#include <algorithm>

int N, a, b, ca, cb, m, _count;

int main(void) {
    scanf("%d", &N);
    a = b = 0;
    _count = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &ca, &cb);

        _count += std::max(1+(std::min(ca,cb) - std::max(a,b)), 0);

        if (ca == cb) _count--;

        a = ca;
        b = cb;
    }

    if (ca == cb) _count++;

    printf("%d\n", _count);
    return 0;
}
