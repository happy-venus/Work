#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int H, W; cin >> H >> W;
  vector<string> pan(H); for (auto& row : pan) cin >> row;
  if (H > W) {
    vector<string> npan(W);
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) npan[j] += pan[i][j];
    pan.swap(npan); swap(H, W);
  }
  const int MX = 2e5;
  vector<bitset<MX>> grid(H);
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (pan[i][j] == '#') grid[i].set(j);
  vector<int> cnt(W+1); long long ans = 1;
  for (int i = 0; i < H; i++) {
    bitset<MX> cur = grid[i];
    for (int j = i; j < H; j++) {
      cur &= grid[j]; int up = 0, down = 0, upper = -1;
      for (int c = 0; c < W; c++) {
        cnt[c+1] = cnt[c] + (!cur[c]);
        if (pan[i][c] == '#') up++;
        else up = 0;
        if (pan[j][c] == '#') down++;
        else down = 0;
        if (!cur[c]) upper = c;
        // <= c-up+1, <= c-down+1, <=upper .. count of safe
        int get = min({c-up, c-down, upper});
        if (!cur[c]) ans += cnt[get+1];
      }
    }
  }
  cout << ans << "\n";
  
  return 0;
}
