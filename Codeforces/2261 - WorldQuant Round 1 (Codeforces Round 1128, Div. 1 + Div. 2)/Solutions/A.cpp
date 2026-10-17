#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> current;
    for (int i = 0; i < N; i++) if (S[i] == '1') current.push_back(i+1);
    if (current.size() == 1) cout << "0\n";
    else if (current.size() == 2) cout << "1\n";
    else cout << current.back() - current[0] << "\n";
  }
  
  return 0;
}
