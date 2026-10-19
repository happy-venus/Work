#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> A(N+1), B(N+1); for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
    vector<pair<int, int>> delta;
    multiset<int> ms;
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
      delta.push_back({A[i]-B[i], i});
      sum += A[i]; ms.insert(A[i]);
    }
    long long ans = sum, cnt = 0;
    sort(delta.begin(), delta.end(), greater<pair<int, int>>());
    for (auto& [err, i] : delta) {
      sum -= err; ms.extract(A[i]); cnt++;
      if (ms.empty()) break;
      ans = min(ans, sum + 1LL * max(cnt - (int)ms.size(), 0LL) * (*ms.begin()));
    }
    cout << ans << "\n";
  }
  
  return 0;
}
