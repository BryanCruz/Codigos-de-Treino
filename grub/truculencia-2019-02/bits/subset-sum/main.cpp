#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int s[37];
int n;
ll r;

int a, b;

int avg(int i, int j) {
    return (i+j)/2;
}

ll x[(1<<17)+1], y[(1<<17)+1];
int i_x;
int i_y;

void generate_sums(int *i_arr, ll* arr, int ii, int jj) {
    ll qtd = jj-ii+1;
    ll qtd_s = llround(pow(2, qtd));

    for(ll i = 0; i < qtd_s; i++, (*i_arr)++) {
        for(ll j = 0; j < qtd; j++) {
            if((i&(1<<j))) {
                arr[*i_arr] += s[ii+j];
            }
        }
    }
}

int bin_search(int k) {
    int i = 0;
    int j = i_y-1;

    int m;
    while(i <= j) {
        m = avg(i,j);

        if (y[m] < k) {
            i = m+1;
        } else if (y[m] > k) {
            j = m-1;
        } else {
            break;
        }
    }

    while (m < i_y & y[m] <= k) m++;

    return m;
}

ll count_between(int min_, int max_) {
    int i_min = bin_search(min_); // first value greater than min_
    int i_max = bin_search(max_); // first value greater than max_

    while(i_min > 0 && y[i_min-1] == min_) i_min--;

    return i_max-i_min;
}

ll count_() {
    int m = avg(0, n-1);
    
    i_x = 0;
    i_y = 0;

    generate_sums(&i_x, x, 0, m);
    generate_sums(&i_y, y, m+1, n-1);

    sort(x, x+i_x);
    sort(y, y+i_y);

    ll c = 0, sum;
    for(int i = 0; i < i_x; i++) {
        c += count_between(a-x[i], b-x[i]);
    }
    return c;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    scanf("%d %d %d", &n, &a, &b);

    for(int i = 0; i < n; i++) {
        scanf("%d", s+i);
    }

    printf("%lld\n", count_());

	return 0;
}
