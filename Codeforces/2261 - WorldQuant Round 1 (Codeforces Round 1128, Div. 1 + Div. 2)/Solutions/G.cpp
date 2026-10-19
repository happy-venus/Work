#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
    vector<vector<pair<int, int>>> stacks(26);
    // first 25 .. min of the candidates
    // last     .. max of the array
    vector<int> change(25), prefix(N+1);
    vector<array<int, 2>> nxt = {{-1, -1}};
    vector<vector<int>> positions = {{}};
    auto Add = [&](int i, int v) {
      int cur = 0;
      for (int b = 24; b >= 0; b--) {
        int n = ((v >> b) & 1);
        if (nxt[cur][n] == -1) nxt[cur][n] = nxt.size(), nxt.push_back({-1, -1}), positions.emplace_back();
        cur = nxt[cur][n]; positions[cur].push_back(i);
      }
    };
    for (int i = 1; i <= N; i++) {
      prefix[i] = prefix[i-1] ^ A[i];
      // find the upper cap
      for (int b = 0; b < 25; b++) if (~A[i] & (1<<b)) {
        // when >= A[i] + (1<<b)
        auto pos = upper_bound(stacks[25].begin(), stacks[25].end(), make_pair(A[i]+(1<<b), 0), greater<pair<int, int>>());
        if (pos == stacks[25].begin()) continue; pos--;
        change[b] = max(change[b], pos->second);
      }
      while (!stacks[25].empty() && stacks[25].back().first <= A[i]) stacks[25].pop_back();
      stacks[25].push_back({A[i], i});
      // find the candidate
      for (int b = 0; b < 25; b++) {
        auto pos = upper_bound(stacks[b].begin(), stacks[b].end(), make_pair(A[i], i));
        if (pos == stacks[b].begin()) continue; pos--;
        change[b] = max(change[b], pos->second);
        if (~A[i] & (1<<b)) {
          int bound = A[i] + (1<<b);
          while (!stacks[b].empty() && stacks[b].back().first >= bound) stacks[b].pop_back();
          stacks[b].push_back({bound, i});
        }
      }
      Add(i, prefix[i-1]);
      for (int b = 24; b >= 0; b--) {
      }
    }
  }
  
  return 0;
}
