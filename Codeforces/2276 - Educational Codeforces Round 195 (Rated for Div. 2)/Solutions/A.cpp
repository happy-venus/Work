#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int a, b; cin >> a >> b;
    cout << (a > b ? min(a-b, b) : -1) << "\n";
  }
  
  return 0;
}
