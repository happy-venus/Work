#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  const int MX = 1e7;
  vector<int> flg(MX+1); flg[1] = 1;
  for (int i = 2; i <= MX; i++) if (!flg[i]) for (int j = i*2; j <= MX; j += i) flg[j] = 1;
  string S; cin >> S; vector<int> vis(26); int cc = 0;
  string tmp;
  for (char c : S) {
    if (!vis[c-'a']) tmp += char('0'+(++cc)), vis[c-'a'] = cc;
    else tmp += char('0'+vis[c-'a']);
  }
  for (int i = 1; i < MX; i++) if (!flg[i]) {
    string num = to_string(i);
    if (num.length() != S.length()) continue;
    vector<int> nvis(10); int ni = 0;
    string comp;
    for (char c : num) {
      if (!nvis[c-'0']) comp += char('0'+(++ni)), nvis[c-'0'] = ni;
      else comp += char('0'+nvis[c-'0']);
    }
    if (tmp == comp) cout << i << "\n", exit(0);
  }
  cout << "-1\n";
  
  return 0;
}
