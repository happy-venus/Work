#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  random_device rnd;
  uniform_int_distribution<long long> gen(0, LLONG_MAX);
  int T; cin >> T;
  while (T--) {
    int N, M; cin >> N >> M;
    vector<long long> arr(N+1);
    for (int i = 1; i <= M; i++) {
      int L, R; cin >> L >> R;
      long long v = gen(rnd);
      arr[R] ^= v; arr[L-1] ^= v;
    }
    assert(M == 0);
    if (N == 1) cout << "0\n";
    else {
      // len 1 2
      cout << (N+1) / 2 << "\n";
      for (int i = 1; i <= (N+1)/2; i++) {
        cout << i+1 << " " << i+1+(N/2-1) << "\n";
      }
    }
    // for (int i = N; i >= 1; i--) arr[i-1] ^= arr[i];
    // map<long long, vector<int>> pos;
    // for (int i = 1; i <= N; i++) pos[arr[i]].push_back(i);
    // vector<vector<int>> vec;
    // for (auto& [h, v] : pos) vec.push_back(v);
    // vector<pair<int, int>> ans;
  }
  
  return 0;
}
