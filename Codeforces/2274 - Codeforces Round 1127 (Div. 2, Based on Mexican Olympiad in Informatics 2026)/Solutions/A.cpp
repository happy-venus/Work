#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
      int x; cin >> x;
      ans += (i % 2 ? x : -x);
    }
    cout << ans << "\n";
  }
  
  return 0;
}
