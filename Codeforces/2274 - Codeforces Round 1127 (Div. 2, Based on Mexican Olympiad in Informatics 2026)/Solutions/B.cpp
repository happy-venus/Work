#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
    int mx = A[1], mn = A[1], ans = A[1];
    for (int i = 2; i <= N; i++) {
      ans = max(ans, A[i] - mn);
      ans = max(ans, A[i] + mx);
      ans = max(ans, A[i]);
      mx = max(A[i], A[i] + 2 * mx);
      mn = min(A[i], A[i] + 2 * mn);
    }
    cout << ans << "\n";
  }
  
  return 0;
}
