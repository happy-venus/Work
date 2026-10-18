#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, Q; cin >> N >> Q;
  vector<int> A(N+1); for(int i = 1; i <= N; i++) cin >> A[i];
  vector<vector<int>> adj(N+1);
  for (int i = 1; i < N; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> tin(N+1), order(2*N); int timer = 0;
  function<void(int, int)> DFS = [&](int u, int p) {
    tin[u] = ++timer; order[timer] = u;
    for (int& v : adj[u]) if (v != p) DFS(v, u), order[++timer] = u;
  }; DFS(1, 0);
  vector<array<int, 5>> queries;
  for (int i = 1; i <= Q; i++) {
    int u, v, s, t; cin >> u >> v >> s >> t;
    if (tin[u] > tin[v]) swap(u, v);
    queries.push_back({u, v, s, t, i});
  }
  int B = 700, L = 1, R = 0; vector<int> cnt(N+1), ccnt(N+2),  ans(Q+1), vis(N+1);
  sort(queries.begin(), queries.end(), [&](const array<int, 5>& x, const array<int, 5>& y) {
    return make_pair(tin[x[0]] / B, tin[x[1]]) < make_pair(tin[y[0]] / B, tin[y[1]]);
  });
  auto Move = [&](int v, int nv) {
    if (vis[nv]) ccnt[cnt[A[v]]--]--, vis[v] = 0;
    else ccnt[++cnt[A[nv]]]++, vis[nv] = 1;
  }; ccnt[0] = N;
  for (auto& [u, v, s, t, q] : queries) {
    while (R < tin[v]) Move(order[R], order[R+1]), R++;
    while (R > tin[v]) Move(order[R], order[R-1]), R--;
    while (L > tin[u]) Move(order[L], order[L-1]), L--;
    while (L < tin[u]) Move(order[L], order[L+1]), L++;
    ans[q] = ccnt[s] - ccnt[t+1];
  }
  for (int i = 1; i <= Q; i++) cout << ans[i] << "\n";
  
  return 0;
}
