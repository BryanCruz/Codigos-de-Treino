
 #include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long unll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define rep(x, y, z)       for(int i = x;i <= y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(i, x)        for(int i = 0;i < x;i++)
#define avg(l, r)          l + (r - l) / 2
#define left(x)            x << 1
#define right(x)           x << 1 | 1
#define pb                 push_back
#define eb                 emplace_back

#define T          5000
#define N          4 * T + 10

int st[N];
void build(vi& v, int id, int l, int r) {
  if (l == r) {
    st[id] = v[l] == 1;
  }
  else {
    int mid = avg(l, r);
    build(v, left(id), l, mid);
    build(v, right(id), mid + 1, r);
    st[id] = st[left(id)] + st[right(id)];
  }
}
int query(int id, int l, int r, int a, int b) {
  // prop(id, l, r);
  if (l > b || r < a) return 0;
  if (l >= a && r <= b) return st[id];
  else {
    int mid = avg(l, r);
    int x = query(left(id), l, mid, a, b);
    int y = query(right(id), mid + 1, r, a, b);
    return x + y;
  }
}

bool comp(tuple<int, int, int>& a, tuple<int, int, int>& b) {
  int a1, a2, a3, b1, b2, b3;
  tie(a1,a2,a3) = a, tie(b1,b2,b3) = b;
  if (a3 < b3) return true;
  else if (a3 == b3) return (a2 - a1 < b2 - b1);
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n, q, l, r;
  cin >> n >> q;
  vb paint(n, false);
  vi x(n, 0);
  deque<tuple<int, int, int>> qs;
  loop(q) {
    cin >> l >> r;
    rep (l, r, 1) {
      paint[i] = ++x[i - 1];
    }
    qs.eb(l - 1, r - 1, 0);
  }
  int count;
  count = 0;
  loop(n) {
    if (x[i]) count++;
  }
  loop(2) {
    build(x, 1, 0, n - 1);
    each(p, qs) {
      int l, r, qtd;
      tie(l, r, qtd) = p;
      get<2>(p) = query(1, 0, n - 1, l, r);
    }
    sort(qs.begin(), qs.end(), comp);
    int l, r, q;
    tie(l, r, q) = qs[0];
    count -= q;
    rep(l, r, 1) {
      x[i]--;
    }
    qs.pop_front();
  }
  cout << count << endl;
  return 0;
}
