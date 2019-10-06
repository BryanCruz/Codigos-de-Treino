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

void find_palyndrome(int i, int j) {

}

int main (void) {
	ios_base::sync_with_stdio(false);

    int n;
    char* c[500+100];
    
    scanf("%d", &n);
    scanf("%s", &c);

    int removed = 0;
    int i = 0;
    int j = n-1;

    while(i < j) {
        if(c[i] == c[j]) {
            i++;
            j--;
        }
    }

	return 0;
}


