#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    string S; cin >> S;
    int ans = 0;
    for (int i = 2; i < S.length(); i++) {
      if (S[i] == S[i-1] && S[i-1] == S[i-2]) ans |= 1;
      if (S[i] != S[i-1] && S[i-1] != S[i-2]) ans |= 2;
    }
    cout << 1 + __builtin_popcount(ans) << "\n";
  }
  
  return 0;
}
