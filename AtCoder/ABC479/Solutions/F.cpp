#include <bits/stdc++.h>
using namespace std;

struct BIT {
  vector<int> bit; int sz;
  BIT(int N) : bit(N+1), sz(N) {}
  inline void Add(int i, int x) { for (; i <= sz; i += (i & (-i))) bit[i] += x; }
  inline int Get(int i) { int r = 0; for (; i; i -= (i & (-i))) r += bit[i]; return r; }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N; cin >> N;
  vector<int> S(N+1), T(N+1);
  for (int i = 1; i <= N; i++) cin >> S[i];
  for (int i = 1; i <= N; i++) cin >> T[i];
  vector<pair<int, int>> arrS, arrT;
  for (int i = 1; i <= N; i++) arrS.push_back({S[i], i});
  for (int i = 1; i <= N; i++) arrT.push_back({T[i], i});
  sort(arrS.begin(), arrS.end());
  sort(arrT.begin(), arrT.end());
  vector<int> posS(N+1), posT(N+1);
  for (int i = 0; i < N; i++) posS[arrS[i].second] = i+1;
  for (int i = 0; i < N; i++) posT[arrT[i].second] = i+1;
  long long ans = 0;
  for (int i = 1; i <= N; i++) ans += abs(S[i]-posS[i]-T[i]+posT[i]);
  vector<int> pos(N+1); BIT bit(N);
  for (int i = 1; i <= N; i++) pos[posS[i]] = posT[i];
  for (int i = N; i >= 1; i--) ans += bit.Get(pos[i]), bit.Add(pos[i], +1);
  cout << ans << "\n";
  
  return 0;
}
