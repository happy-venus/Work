#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, M, K; cin >> N >> M >> K;
  string T; cin >> T;
  vector<vector<bool>> arr(N+1);
  vector<array<int, 3>> nxt = {{-1, -1, N}};
  auto Add = [&](int i, int v) {
    int cur = 0;
    for (int j = 0; j < K; j++) {
      if (nxt[cur][arr[i][j]] == -1) {
        nxt[cur][arr[i][j]] = nxt.size();
        nxt.push_back({-1, -1, 0});
      }
      cur = nxt[cur][arr[i][j]];
      nxt[cur][2] += v;
    }
  };
  for (int i = 1; i <= N; i++) {
    string S; cin >> S;
    for (int j = 0; j < K; j++) arr[i].push_back(S[j] == T[j]);
    Add(i, +1);
  }
  int Q; cin >> Q;
  while (Q--) {
    int i, j; cin >> i >> j;
    Add(i, -1);
    arr[i][j-1] = !arr[i][j-1];
    Add(i, +1);
    int cur = 0, qualified = 0, unqualified = 0;
    bool flag = false;
    for (int c = 0; c < K && cur != -1; c++) {
      int n = nxt[cur][1];
      int s = (n == -1 ? 0 : nxt[n][2]);
      if (qualified + s <= M) {
        qualified += s;
        cur = nxt[cur][0];
        if (arr[i][c] == 1) {
          flag = true;
          break;
        }
      } else {
        unqualified += nxt[cur][2] - s;
        cur = nxt[cur][1];
        if (arr[i][c] == 0) {
          flag = false;
          break;
        }
      }
    }
    cout << (flag ? "Yes\n" : "No\n");
  }
  
  return 0;
}
