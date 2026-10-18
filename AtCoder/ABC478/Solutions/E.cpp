#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, Q; cin >> N >> Q;
  vector<pair<int, int>> ban;
  vector<vector<int>> adj(N+1), radj(N+1);
  for (int i = 1; i <= Q; i++) {
    int type, u, v; cin >> type >> u >> v;
    adj[u].push_back(v);
    radj[v].push_back(u);
    if (type == 1) ban.push_back({u, v});
  }
  vector<int> order, vis(N+1), comp(N+1);
  function<void(int)> DFS = [&](int u) {
    vis[u] = 1;
    for (int& v : adj[u]) if (!vis[v]) DFS(v);
    order.push_back(u);
  };
  for (int i = 1; i <= N; i++) if (!vis[i]) DFS(i);
  reverse(order.begin(), order.end());
  function<void(int, int)> dfs = [&](int u, int c) {
    vis[u] = 0; comp[u] = c;
    for (int& v : radj[u]) if (vis[v]) dfs(v, c);
  }; int cur = 0;
  for (int& u : order) if (vis[u]) dfs(u, ++cur);
  for (auto& [u, v] : ban) if (comp[u] == comp[v]) cout << "No", exit(0);
  cout << "Yes\n";
  for (int i = 1; i <= N; i++) cout << comp[i] << " \n"[i == N];
  
  return 0;
}
