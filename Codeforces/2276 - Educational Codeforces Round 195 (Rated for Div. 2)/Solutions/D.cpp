#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N, M; cin >> N >> M;
    vector<int> deg(N+1);
    for (int i = 1; i <= M; i++) {
      int u, v; cin >> u >> v;
      deg[u]++; deg[v]++;
    }
    if (*min_element(deg.begin()+1, deg.end()) == 0) {
      cout << "Brain Melt\n";
      continue;
    }
    if (M == N-1 && *max_element(deg.begin()+1, deg.end()) == N-1) cout << "2\n";
    else cout << "Many\n";
  }
  
  return 0;
}
