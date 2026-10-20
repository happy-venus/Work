#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int H, W, K; cin >> H >> W >> K;
  vector<string> pan(H); for (auto& row : pan) cin >> row;
  vector<int> row(H), col(W);
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (pan[i][j] == '#') row[i]++, col[j]++;
  vector<vector<int>> dis(H, vector<int>(W, -1));
  queue<pair<int, int>> bfs;
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (row[i] + col[j] == 0) {
    bfs.push({i, j}); dis[i][j] = 0;
  }
  vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
  int ans = 0;
  while (!bfs.empty()) {
    auto [x, y] = bfs.front(); bfs.pop();
    if (dis[x][y] <= K) ans++;
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || nx >= H || ny < 0 || ny >= W || pan[nx][ny] == '#' || dis[nx][ny] != -1) continue;
      bfs.push({nx, ny}); dis[nx][ny] = dis[x][y] + 1;
    }
  }
  cout << ans << "\n";
  
  return 0;
}
