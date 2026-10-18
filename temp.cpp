#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> sz;
  DSU(int N) : sz(N+1, -1) {}
  inline int Root(int u) { return sz[u] < 0 ? u : sz[u] = Root(sz[u]); }
  inline bool Merge(int u, int v) {
    u = Root(u), v = Root(v);
    if (u == v) return false;
    if (sz[u] > sz[v]) swap(u, v);
    sz[u] += sz[v]; sz[v] = u;
    return true;
  }
};

struct SegTree {
  vector<int> seg; int sz;
  SegTree(int N) {
    for (sz = 1; sz < N; sz *= 2);
    seg = vector<int>(sz*2);
  }
  inline void Set(int i, int x) {
    seg[i += sz - 1] = x;
    while (i /= 2) seg[i] = max(seg[i*2], seg[i*2+1]);
  }
  inline int Get(int l, int r, int i, int L, int R) {
    if (l == L && r == R) return seg[i];
    int md = (L + R) / 2;
    if (r <= md) return Get(l, r, i*2, L, md);
    else if (l > md) return Get(l, r, i*2+1, md+1, R);
    else return max(Get(l, md, i*2, L, md), Get(md+1, r, i*2+1, md+1, R));
  }
  inline int Get(int l, int r) { return Get(l, r, 1, 1, sz); }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, M; cin >> N >> M;
  vector<array<int, 3>> edges(M);
  for (auto& [w, u, v] : edges) cin >> u >> v >> w;
  for (auto& [w, u, v] : edges) u++, v++;
  sort(edges.begin(), edges.end());
  vector<vector<pair<int, int>>> adj(N+1); DSU dsu(N);
  for (auto& [w, u, v] : edges) {
    if (dsu.Merge(u, v)) adj[u].push_back({v, w}), adj[v].push_back({u, w});
  }
  vector<vector<int>> par(N+1, vector<int>(20)); vector<int> dp(N+1);
  function<void(int, int)> DFS = [&](int u, int p) {
    dp[u] = dp[p] + 1; par[u][0] = p;
    for (int i = 1; i < 20; i++) par[u][i] = par[par[u][i-1]][i-1];
    for (auto& [v, w] : adj[u]) if (v != p) DFS(v, u);
  }; DFS(1, 0);
  auto LCA = [&](int u, int v) {
    if (dp[u] < dp[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) if (dp[u] >= dp[v] + (1<<i)) u = par[u][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
    return par[u][0];
  };
  vector<vector<pair<int, int>>> queries(N+1);
  for (int i = 0; i < M; i++) {
    auto [w, u, v] = edges[i];
    int anc = LCA(u, v);
    if (u != anc) queries[u].push_back({anc, i});
    if (v != anc) queries[v].push_back({anc, i});
  }
  SegTree ST(N);
  vector<int> wei(M);
  function<void(int, int)> Solve = [&](int u, int p) {
    for (auto& [v, w] : adj[u]) if (v != p) {
      ST.Set(dp[u], w);
      Solve(v, u);
    }
    for (auto& [anc, e] : queries[u]) wei[e] = max(wei[e], ST.Get(dp[anc], dp[u]-1));
  }; Solve(1, 0);
  int ans = 1-N;
  for (int i = 0; i < M; i++) if (wei[i] == edges[i][0]) ans++;
  cout << ans << "\n";
  
  return 0;
}
