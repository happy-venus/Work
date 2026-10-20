#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N+1);
    for (int i = 1; i <= M; i++) {
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> color(N+1, -1), par(N+1), cycle;
    function<void(int)> DFS = [&](int u) {
      for (int& v : adj[u]) {
        if (!cycle.empty()) return;
        if (color[v] == -1) {
          color[v] = !color[u];
          par[v] = u; DFS(v);
        } else if (color[u] == color[v]) {
          cycle = {u};
          while (cycle.back() != v) cycle.push_back(par[cycle.back()]);
        }
      }
    }; color[1] = 0, DFS(1);
    if (cycle.empty()) cout << "-1\n";
    else {
      cout << cycle.size() << "\n";
      for (int& x : cycle) cout << x << " ";
      cout << "\n";
    }
  }
  
  return 0;
}
