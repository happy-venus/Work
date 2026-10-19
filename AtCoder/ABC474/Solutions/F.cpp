#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N; cin >> N;
  vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
  vector<vector<int>> div(N+1);
  for (int i = 1; i <= N; i++) for (int j = i; j <= N; j += i) div[j].push_back(i);
  vector<int> cur(N+1), inc(N+1);
  for (int i = N; i >= 1; i--) {
    cur[i] = -A[i];
    for (int& j : div[i]) A[j] += cur[i];
  }
  for (int i = N; i >= 1; i--) {
    inc[i] = 1-A[i];
    for (int& j : div[i]) A[j] += inc[i];
  }
  int L = 0, R = LLONG_MAX, a = 0, b = 0;
  for (int i = 1; i <= N; i++) {
    // cur[i] + inc[i] * x >= 0
    a += cur[i], b += inc[i];
    if (inc[i] == 0 && cur[i] < 0) cout << "-1\n", exit(0);
    if (inc[i] == 0) continue;
    if (inc[i] > 0) {
      // inc[i] * x >= -cur[i]
      int v = max(-cur[i], 0LL);
      L = max(L, (v+inc[i]-1)/inc[i]);
    } else {
      // -inc[i] * x <= cur[i]
      R = min(R, cur[i] < 0 ? -1LL : cur[i] / (-inc[i]));
    }
  }
  if (L > R) cout << "-1\n", exit(0);
  cout << min(a+b*L, a+b*R) << "\n";
  
  return 0;
}
