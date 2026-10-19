#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  const int MX = 62;
  vector<vector<int>> C(MX+1, vector<int>(MX+1));
  for (int i = 0; i <= MX; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i-1][j] + C[i-1][j-1];
  }
  int T; cin >> T;
  while (T--) {
    int L, R; cin >> L >> R;
    vector<int> dp(61); R++;
    while (L < R) {
      int b = min(__builtin_ctzll(L), 63-__builtin_clzll(L^R));
      for (int i = 0; i <= b; i++) {
        dp[__builtin_popcountll(L) + i] += C[b][i];
      }
      for (int i = 60; i >= 1; i--) dp[i-1] = max(dp[i-1], dp[i]);
      L += (1LL<<b);
    }
    cout << dp[0] << "\n";
  }
  
  return 0;
}
