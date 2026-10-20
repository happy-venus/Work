#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N; cin >> N;
  vector<int> L(N+1); for (int i = 1; i <= N; i++) cin >> L[i];
  for (int i = 1; i <= N; i++) L[i] += L[i-1];
  int ans = L[N];
  for (int i = 1; i <= N; i++) ans = min(ans, abs(L[N]-L[i]*2));
  cout << ans << "\n";
  
  return 0;
}
