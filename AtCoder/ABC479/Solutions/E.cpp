#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N; cin >> N;
  vector<vector<pair<int, int>>> adj(N+1);
  for (int i = 1; i < N; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  vector<int> tin(N+1), tout(N+1), arr(N+1); int timer = 0;
  function<void(int, int, int)> DFS = [&](int u, int p, int e) {
    tin[u] = ++timer;
    for (auto& [v, e] : adj[u]) if (v != p) DFS(v, u, e);
    tout[u] = timer;
    int s = tout[u] - tin[u] + 1;
    if (s > N - s) arr[tout[u]]+=e, arr[tin[u]-1]-=e;
    else arr[N]+=e, arr[tout[u]]-=e, arr[tin[u]-1]+=e;
  }; DFS(1, 0, 0);
  for (int i = N; i >= 1; i--) arr[i-1] += arr[i];
  for (int i = 1; i <= N; i++) cout << arr[tin[i]] << " \n"[i == N];
  
  return 0;
}
