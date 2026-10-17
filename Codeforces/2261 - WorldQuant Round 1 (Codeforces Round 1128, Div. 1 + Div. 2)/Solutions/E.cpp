#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N, K; cin >> N >> K;
    string S; cin >> S;
    int ans = K;
    int cur = 0;
    for (int i = 0; i < N; i++) {
      cur += (S[i] == '(' ? +1 : -1);
      // i+1, cur
      int rem = (i+1-cur) / 2;
      if (rem <= K) {
        int other = (N - (i+1) - cur) / 2;
        int op = min(other, K - rem);
        ans = max(ans, cur + op + rem);
      }
    }
    vector<int> arr = {0};
    for (int i = 0; i < N; i++) {
      cur += (S[i] == '(' ? +1 : -1);
      if (S[i] == ')') arr.pop_back();
      else arr.push_back(0);
      arr.back() = (i+1-cur) / 2;
      ans = max(ans, (int)(arr.end()-lower_bound(arr.begin(), arr.end(), arr.back()-K)-1));
    }
    cout << ans << "\n";
  }
  
  return 0;
}
