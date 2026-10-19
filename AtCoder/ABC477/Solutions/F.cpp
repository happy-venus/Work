#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SegTree {
  vector<int> segv, segf; int sz;
  SegTree(int N) {
    for (sz = 1; sz < N; sz *= 2);
    segv = segf = vector<int>(sz*2);
  }
  inline void Down(int i, int len) {
    AddOP(i*2, len, segf[i]);
    AddOP(i*2+1, len, segf[i]);
    segf[i] = 0;
  }
  inline void AddOP(int i, int len, int x) {
    segv[i] += x * len;
    segf[i] += x;
  }
  inline void Operate(int l, int r, int x, int i, int L, int R) {
    if (l == L && r == R) return AddOP(i, R-L+1, x);
    int md = (L + R) / 2; Down(i, R-md);
    if (r <= md) Operate(l, r, x, i*2, L, md);
    else if (l > md) Operate(l, r, x, i*2+1, md+1, R);
    else Operate(l, md, x, i*2, L, md), Operate(md+1, r, x, i*2+1, md+1, R);
    segv[i] = segv[i*2] + segv[i*2+1];
  }
  inline int Get(int l, int r, int i, int L, int R) {
    if (l == L && r == R) return segv[i];
    int md = (L + R) / 2; Down(i, R-md);
    if (r <= md) return Get(l, r, i*2, L, md);
    else if (l > md) return Get(l, r, i*2+1, md+1, R);
    else return Get(l, md, i*2, L, md) + Get(md+1, r, i*2+1, md+1, R);
  }
  inline void Operate(int l, int r, int x) { return Operate(l, r, x, 1, 1, sz); }
  inline int Get(int l, int r) { return Get(l, r, 1, 1, sz); }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, M, Q; cin >> N >> M >> Q;
  vector<int> L(N+1), R(N+1); SegTree ST(M);
  vector<int> ans(Q+1); vector<vector<array<int, 4>>> queries(N+1);
  for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];
  for (int i = 1; i <= Q; i++) {
    int A, B, C, D; cin >> A >> B >> C >> D;
    queries[B].push_back({C, D, i, +1});
    queries[A-1].push_back({C, D, i, -1});
  }
  for (int i = 1; i <= N; i++) {
    ST.Operate(L[i], R[i], 1);
    for (auto& [l, r, q, c] : queries[i]) ans[q] += ST.Get(l, r) * c;
  }
  for (int i = 1; i <= Q; i++) cout << ans[i] << "\n";
  
  return 0;
}
