#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> op, cur = {2*N-2, 2*N-1, 2*N};
    for (int round = 0; round < 3; round++) {
      int x = cur.back(); cur.pop_back();
      for (int i = x; i >= 2; i -= 2) {
        op.push_back(i);
        for (int& y : cur) y = (y == 2*N ? 2*N-2 : y+1);
      }
    }
    cout << op.size() << "\n";
    for (int& x : op) cout << x << " "; cout << "\n";
  }
  
  return 0;
}
