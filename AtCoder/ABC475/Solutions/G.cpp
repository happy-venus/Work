#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  vector<int> primes;
  for (int i = 2; i <= 200; i++) {
    primes.push_back(i);
    for (int j = 2; j < i; j++) if (i % j == 0) {
      primes.pop_back();
      break;
    }
  }
  int T; cin >> T;
  while (T--) {
    int N, D; cin >> N >> D;
    vector<pair<int, int>> ban;
    for (int& p : primes) {
      int c = 0;
      while (D % p == 0) D /= p, c++;
      if (c) ban.push_back({p, c});
    }
    if (D > 1) ban = {{200, 1}};
    pair<int, int> ans = {1, 1};
    for (auto& [p, c] : ban) {
      function<void(int, int, int, int)> DFS = [&](int pos, int exp, int cur, int count) {
        if (exp == 0) {
          for (int i = 0; i < c && cur <= N; i++) {
            ans = max(ans, make_pair(count * (i+1), cur));
            if (LLONG_MAX / cur >= p) cur *= p;
            else cur = LLONG_MAX;
          }
          return;
        }
        if (p == primes[pos]) return DFS(pos+1, exp, cur, count);
        for (int i = 0; i <= exp && cur <= N; i++) {
          DFS(pos+1, i, cur, count*(i+1));
          if (LLONG_MAX / cur >= primes[pos]) cur *= primes[pos];
          else cur = LLONG_MAX;
        }
      }; DFS(0, 100, 1, 1);
    }
    cout << ans.second << "\n";
  }
  
  return 0;
}
