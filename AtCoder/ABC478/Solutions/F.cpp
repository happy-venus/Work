#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N; cin >> N;
  vector<int> P(N+1); for (int i = 1; i <= N; i++) cin >> P[i];
  int ans = 1; stack<int> st; st.push(1);
  for (int i = 2; i <= N; i++) {
    while (!st.empty() && P[st.top()] < P[i]) st.pop();
    ans = 1LL * ans * (st.empty() ? i-1 : i-st.top()) % MOD;
    st.push(i);
  }
  cout << ans << "\n";
  
  return 0;
}
