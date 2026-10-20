#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int H, W; cin >> H >> W;
  vector<string> pan(H); for (auto& s : pan) cin >> s;
  vector<vector<array<int, 3>>> ranges(H);
  for (int i = 0; i < H; i++) {
    vector<int> pos = {-1};
    for (int j = 0; j < W; j++) if (pan[i][j] == '#') pos.push_back(j);
    pos.push_back(W);
    for (int j = 1; j < pos.size(); j++) {
      if (pos[j] != pos[j-1] + 1) {
        int c = 0;
        for (int k = pos[j-1]+1; k < pos[j]; k++) c += (pan[i][k] == '+' ? +1 : -1);
        ranges[i].push_back({pos[j-1]+1, pos[j]-1, c});
      }
    }
  }
  vector<int> dp = {0};
  for (int i = 0; i < H; i++) {
    int n1 = __builtin_ctz(dp.size()), n2 = ranges[i].size();
    vector<int> ndp(1<<n2, -1e9), con(n1);
    for (int x = 0; x < n1; x++) {
      for (int y = 0; y < n2; y++) {
        if (ranges[i-1][x][0] <= ranges[i][y][1] && ranges[i][y][0] <= ranges[i-1][x][1]) {
          // ranges coincide
          con[x] |= (1<<y);
        }
      }
    }
    for (int m1 = 0; m1 < (1<<n1); m1++) {
      int m2 = 0;
      for (int j = 0; j < n1; j++) if (m1 & (1<<j)) m2 |= con[j];
      ndp[m2] = max(ndp[m2], dp[m1]);
    }
    for (int j = 0; j < n2; j++) for (int m2 = 0; m2 < (1<<n2); m2++) if (m2 & (1<<j)) ndp[m2] = max(ndp[m2], ndp[m2-(1<<j)]);
    for (int m2 = 0; m2 < (1<<n2); m2++) {
      for (int j = 0; j < n2; j++) if (~m2 & (1<<j)) {
        ndp[m2] += ranges[i][j][2];
      }
    }
    dp.swap(ndp);
  }
  cout << *max_element(dp.begin(), dp.end());
  
  return 0;
}
