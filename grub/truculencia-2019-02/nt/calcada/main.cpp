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

int mdc(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return mdc(b, a % b);
}

int main (void) {
	ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    int a,b,c,d;
    
    while(T--){
        cin >> a >> b >> c >> d;    

        a = abs(c-a);
        b = abs(d-b);

        cout << ((a==0&&b==0)?0:mdc(a, b))+1 << endl;
    }

	return 0;
}


