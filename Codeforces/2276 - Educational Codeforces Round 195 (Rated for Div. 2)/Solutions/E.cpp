#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    string S; cin >> S;
    vector<vector<int>> pos(N+1, vector<int>(10, N));
    vector<long long> calc(N+1);
    for (int i = N-1; i >= 0; i--) {
      pos[i] = pos[i+1];
      pos[i][S[i]-'0'] = i;
      int L = i, R = i;
      for (char c : {'2', '0', '2', '5'}) L = pos[L][c-'0'];
      for (char c : {'2', '0', '2', '6'}) R = pos[R][c-'0'];
      // [L, R)
      if (L < R) {
        calc[L] += 1; calc[R] -= 1;
        if (i) calc[i-1] -= R-L, calc[i] += R-L;
      }
    }
    for (int i = 1; i <= N; i++) calc[i] += calc[i-1];
    for (int i = N; i >= 1; i--) calc[i-1] += calc[i];
    for (int i = 0; i < N; i++) cout << 1LL * (i+1) * (N-i) - calc[i] << " \n"[i == N-1];
  }
  
  return 0;
}
