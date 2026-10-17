#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
    int odd = 0, even = 0;
    for (int i = 1; i <= N; i++) (A[i] % 2 ? odd : even)++;
    if (odd % 2 == 0 || N == 1) cout << "Moggity\n";
    else if (odd == 1) cout << (even == 1 ? "Larpity\n" : "Moggity\n");
    else cout << (N == 3 ? "Larpity\n" : "Moggity\n");
  }
  
  return 0;
}
