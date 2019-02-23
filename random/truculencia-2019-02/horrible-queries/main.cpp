#include <stdio.h>
#include <algorithm>
#include <string.h>

#define MAX 2000000
long long n, c;
long long q, v;
long long l, r, T;
long long st[4*MAX+10];
long long dv[4*MAX+10];

void build() {
    memset(st, 0, sizeof(long long)*(4*n+10));
    memset(dv, 0, sizeof(long long)*(4*n+10));
}

long long avg(long long a, long long b) {
    return (a / 2) + (b / 2) + ((a % 2 + b % 2) / 2);
}

void update(long long i, long long cl, long long cr) {
    st[i] += (cr-cl+1)*dv[i];
}

void propagate(long long i, long long cl, long long cr) {
    dv[i<<1]   += dv[i];
    dv[i<<1|1] += dv[i];
}

long long _get(long long i, long long cl, long long cr) {
    if(cl > cr) return 0;

    if (dv[i] != 0) {
        update(i, cl, cr);
        if (cl != cr)
            propagate(i, cl, cr);
        dv[i] = 0;
    }

    if (cl >= l && cr <= r) {
        return st[i];
    }

    if (cr < l || cl > r) { 
        return 0;
    }
    
    long long m = avg(cl, cr);
    return _get(i<<1, cl, m) + _get(i<<1|1, m+1, cr);
}

long long _set(long long i, long long cl, long long cr) {
    if(cl > cr) return 0;

    if (dv[i] != 0) {
        update(i, cl, cr);
        if (cl != cr)
            propagate(i, cl, cr);
        dv[i] = 0;
    }

    if (cl >= l && cr <= r) {
        dv[i] += v;
        update(i, cl, cr);
        propagate(i, cl, cr);
        dv[i] = 0;
    } else if (!(cr < l || cl > r)) {
        long long m = avg(cl, cr);
        st[i] = _set(i<<1, cl, m) + _set(i<<1|1, m+1, cr);
    }

    return st[i];
}

void query() {

    scanf("%lld %lld %lld", &q, &l, &r);

    if(q) {
        printf("%lld\n", _get(1, 1, n));
    } else {
        scanf("%lld", &v);

        _set(1, 1, n);
    }
}

int main(void) {
    scanf("%lld", &T);

    while (T--) {
        scanf("%lld %lld", &n, &c);

        build();
        
        while (c--) {
            query();
        }        
    }
    return 0;
}
