#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N, K; cin >> N >> K;
    vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
    vector<int> prefix(N+1); map<int, int> mp;
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
      prefix[i] = (prefix[i-1] + A[i]) % K;
      if (i > K) mp[prefix[i-K-1]]++;
      ans += mp[prefix[i]];
    }
    cout << ans << "\n";
  }
  
  return 0;
}
