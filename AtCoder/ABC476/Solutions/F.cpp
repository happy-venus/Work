#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, M; cin >> N >> M;
  vector<int> A(N+1), B(N+1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= N; i++) cin >> B[i];
  vector<vector<int>> arr(N+1, vector<int>(N+1));
  for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) arr[i][j] = 1LL * A[i] * B[j] % M;
  vector<vector<int>> ans(N+1, vector<int>(N+1));
  for (int round = 0; round < 4; round++) {
    vector<vector<int>> dp(N+1, vector<int>(N+1)), sum(N+1, vector<int>(N+1));
    auto Get = [&](int r, int c, int x, int y) {
      while (c > N) c--, r--, y += x;
      while (c < 1) c++, r--, y += x;
      if (r < 1) return 0LL;
      return dp[r][c] * x + sum[r][c] * y;
    };
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        sum[i][j] = Get(i-1, j-1, 0, 1) + Get(i-1, j+1, 0, 1) + Get(i-2, j, 0, -1) + arr[i-1][j] + arr[i][j];
        dp[i][j] = Get(i-1, j-1, 1, 1) + Get(i-1, j+1, 1, 1) + Get(i-2, j, -1, -2) + arr[i-1][j];
        if (round % 2) ans[i][j] += dp[i][j];
        else ans[i][j] += Get(i-1, j, 1, 1);
      }
    }
    vector<vector<int>> narr(N+1, vector<int>(N+1));
    vector<vector<int>> nans(N+1, vector<int>(N+1));
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        narr[j][N-i+1] = arr[i][j];
        nans[j][N-i+1] = ans[i][j];
      }
    }
    arr.swap(narr); ans.swap(nans);
  }
  int res = 0;
  for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) res ^= (ans[i][j] + (i-1)*N + (j-1));
  cout << res << "\n";
  
  return 0;
}
