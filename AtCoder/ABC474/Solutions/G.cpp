#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N, K; cin >> N >> K;
    if (N % 2 == 0 || K > (N*N-1)/2 || K < N-1 || (K+N)%2 == 0) {
      cout << "No\n";
      continue;
    }
    int row = K / (N-1), rem = K % (N-1);
    string ans;
    for (int i = 1; i < row; i++) ans += string(N-1, 'R') + "D" + string(N-1, 'L') + "D";
    int downcount = N + 1 - row * 2;
    int addition = (N - 1 - rem) / 2;
    for (int i = 0; i < addition; i++) ans += string(downcount, 'D') + "R" + string(downcount, 'U') + "R";
    if (rem) {
      assert(downcount > 0);
      ans += string(rem, 'R') + "D" + string(rem, 'L') + "D";
      downcount -= 2;
      for (int i = 0; i < rem; i += 2) ans += string(downcount, 'D') + "R" + string(downcount, 'U') + "R";
    }
    ans += string(downcount, 'D');
    cout << "Yes\n" << ans << "\n";
  }
  
  return 0;
}
