#include <bits/stdc++.h>
using namespace std;

struct SegTree {
  using V = pair<int, int>;
  vector<V> seg; int sz;
  SegTree(int N) {
    for (sz = 1; sz < N; sz *= 2);
    seg = vector<V>(sz*2);
  }
  inline V Merge(V x, V y) { return {min(x.first, y.first), max(x.second, y.second)}; }
  inline void Set(int i, int v) {
    seg[i += sz - 1] = {v, v};
    while (i /= 2) seg[i] = Merge(seg[i*2], seg[i*2+1]);
  }
  inline V Get(int l, int r, int i, int L, int R) {
    if (l == L && r == R) return seg[i];
    int md = (L + R) / 2;
    if (r <= md) return Get(l, r, i*2, L, md);
    else if (l > md) return Get(l, r, i*2+1, md+1, R);
    else return Merge(Get(l, md, i*2, L, md), Get(md+1, r, i*2+1, md+1, R));
  }
  inline V Get(int l, int r) { return Get(l, r, 1, 1, sz); }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, M; cin >> N >> M; SegTree ST(N);
  vector<int> P(N+1); for (int i = 1; i <= N; i++) cin >> P[i];
  vector<int> pos(N+1); for (int i = 1; i <= N; i++) pos[P[i]] = i;
  for (int i = 1; i <= N; i++) ST.Set(i, P[i]);
  while (M--) {
    int L, R; cin >> L >> R;
    auto [x, y] = ST.Get(L, R);
    swap(pos[x], pos[y]);
    swap(P[pos[x]], P[pos[y]]);
    ST.Set(pos[x], P[pos[x]]);
    ST.Set(pos[y], P[pos[y]]);
  }
  for (int i = 1; i <= N; i++) cout << P[i] << " \n"[i == N];
  
  return 0;
}
