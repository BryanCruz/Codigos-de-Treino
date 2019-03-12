#include <bits/stdc++.h>

using namespace std;

const long long MAX = pow(2, 16);

list<long long> primes;

void generate_primes() {
    bitset<MAX+1> sieve;
    sieve.set(false);
    
    for (long long i = 2; i <= MAX; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
    
            for (long long j = 0; i*i + j*i <= MAX; j++) {
                sieve[j*i+i*i] = true;
            }
        }
    }
}


int main(void) {
    generate_primes();

    long long n;
    long long result;

    while (~scanf("%lld", &n)) {
        result = n;
        bool prime = true;

        for(list<long long>::iterator it = primes.begin(); it != primes.end() && *it <= n; it++) {
            if (n % *it == 0) {
                result /= *it;
                result *= *it - 1;

                while (n % *it == 0) n /= *it;
            }
        }

        if (n > 1) {
            result /= n;
            result *= n - 1;
        }

        long long n_coprimes = result;
        long long n_stars    = n_coprimes/2;

        printf("%lld\n", n_stars);
    }

    return 0;
}

