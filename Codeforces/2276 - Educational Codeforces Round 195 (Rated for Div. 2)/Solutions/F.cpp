#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N, K; cin >> N >> K;
    vector<int> P(N+1); for (int i = 1; i <= N; i++) cin >> P[i];
    vector<int> vis(N+1), cycles;
    for (int i = 1; i <= N; i++) if(!vis[i]) {
      int s = 0;
      for (int j = i; !vis[j]; j = P[j]) vis[j] = 1, s++;
      cycles.push_back(s);
    }
    sort(cycles.begin(), cycles.end());
    if (K == 1) {
      int c1 = lower_bound(cycles.begin(), cycles.end(), 2) - cycles.begin();
      if (cycles.back() > 2) cout << "Bob\n";
      else if (c1 == N) cout << "Alice\n";
      else cout << (c1 % 2 ? "Alice\n" : "Bob\n");
    } else if (cycles.back() > K+1) cout << "Bob\n";
    else if (cycles.back() == K+1) {
      int c1 = 0, sum = 0;
      cycles.pop_back();
      for (int& x : cycles) {
        if (x == 1) c1++;
        else sum += x;
      }
      // sum -> 0 .. c1 % (K+1) == 0
      if (sum > K) cout << "Bob\n";
      else if (sum == 0 && c1 % (K+1) == 0) cout << "Bob\n";
      else if (sum == K && c1 % (K+1) != 0) cout << "Bob\n";
      else if (sum + c1 % (K+1) > K) cout << "Bob\n";
      else cout << "Alice\n";
    } else {
      int c1 = 0, c2 = 0, sum = 0, c = 0;
      vector<vector<int>> dp(K+1, vector<int>(K+1, 0)); dp[0][0] = 1;
      for (int& x : cycles) {
        if (x == 1) c1++;
        else if (x == 2) c2++;
        else {
          sum += x; c++;
          for (int i = K; i >= 1; i--) for (int j = x; j <= K; j++) if (dp[i-1][j-x]) dp[i][j] = 1;
        }
      }
      if (sum <= K) {
        cout << "Alice\n";
        continue;
      }
      bool flag = false;
      for (int i = 0; i <= K; i++) for (int j = 0; j <= K; j++) if (dp[i][j]) {
        int osum = j + min((K-j)/2, c2) * 2;
        int ocnt = i + min((K-j)/2, c2);
        if (sum + c2 - c - osum + ocnt <= K) flag = true;
      }
      cout << (flag ? "Alice\n" : "Bob\n");
    }
  }
  
  return 0;
}
