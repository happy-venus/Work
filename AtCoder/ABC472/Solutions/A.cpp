#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  string S; cin >> S;
  for (char& c : S) if (c != 'A') c = '.';
  cout << S << "\n";
  
  return 0;
}
