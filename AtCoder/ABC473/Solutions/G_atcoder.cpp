#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  using mint = static_modint<998244353>;
  int N, K; cin >> N >> K;
  // probability that pop x as before other x-1 cards are shown
  if (K >= 2*N) cout << "0\n", exit(0);
  vector<mint> fact(N+1, 1), iv(N+1, 1);
  for (int i = 2; i <= N; i++) iv[i] = (mint::mod() - mint::mod() / i) * iv[mint::mod() % i];
  function<vector<mint>(int, int)> DFS = [&](int L, int R) {
    if (L == R) return vector<mint>{iv[L], 1 - iv[L]};
    int md = (L + R) / 2;
    return convolution(DFS(L, md), DFS(md+1, R));
  }; cout << DFS(1, N)[K-N].val() << "\n";
  
  return 0;
}
