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

const int MAX  = 1000000000;
const int MAX2 = sqrt(1000000000);

list<int> primes;

void generate_primes() {
    vector<bool> sieve(MAX2+1, false);

    for (int i = 2; i <= MAX2; i++) {
        if (!sieve[i]) {
            primes.push_back(i);

            for (int j = i*i; j <= MAX2; j+=i) {
                sieve[j] = true;
            }
        }
    }
}

void print_primes(int m, int n) {
    bool primo;
    for (int i = max(2, m); i <= n; i++) {
        primo = true;

        for (list<int>::iterator it = primes.begin(); it != primes.end() && (*it)*(*it) <= i; it++) {
            if (i % *it == 0) {
                primo = false;
                break;
            }
        }
        if (primo) printf("%d\n", i);
    }
}

int main (void) {
	ios_base::sync_with_stdio(false);

    generate_primes();

    int T, m, n;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &m, &n);

        print_primes(m, n);

        if (T > 0) printf("\n");
    }
	return 0;
}


