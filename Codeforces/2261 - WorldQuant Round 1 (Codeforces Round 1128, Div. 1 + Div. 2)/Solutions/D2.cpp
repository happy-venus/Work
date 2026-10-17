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
    for (int i = N; i >= 1; i--) arr[i-1] ^= arr[i];
    map<long long, vector<int>> pos;
    for (int i = 1; i <= N; i++) pos[arr[i]].push_back(i);
    vector<pair<int, int>> ans;
    function<vector<vector<int>>(int, int, bool)> DFS = [&](int L, int R, bool cov) {
      if (L >= R) return vector<vector<int>>{};
      if (cov) {
        vector<vector<int>> res;
        auto vec = pos[arr[L]];
        for (int i = 1; i < vec.size(); i++) {
          auto ret = DFS(vec[i-1]+1, vec[i]-1, false);
          if (ret.empty()) ret = {{vec[i-1]}};
          for (auto x : ret) res.push_back(x);
        }
        vector<int> tmp;
        for (auto ret : res) for (auto x : ret) tmp.push_back(x);
        for (int i = 0; i < (tmp.size()-1) / 2; i++) ans.push_back({tmp[i]+1, tmp[i+(tmp.size()+1)/2]});
        if (tmp.size() % 2 == 1) return vector<vector<int>>{{tmp[tmp.size()/2]}};
        else return vector<vector<int>>{{tmp[tmp.size()/2-1], tmp.back()}};
      } else {
        vector<vector<int>> res; int count = 0;
        for (int i = L; i <= R; ) {
          auto vec = pos[arr[i]];
          auto ret = DFS(vec[0], vec.back(), true);
          if (!ret.empty()) count++;
          for (auto x : ret) res.push_back(x);
          i = vec.back() + 1;
        }
        if (count == 0) return vector<vector<int>>{};
        else if (count == 1) return res;
        else {
          vector<int> tmp;
          for (auto ret : res) for (auto x : ret) tmp.push_back(x);
          for (int i = 0; i < (tmp.size()-1) / 2; i++) ans.push_back({tmp[i]+1, tmp[i+(tmp.size()+1)/2]});
          if (tmp.size() % 2 == 1) return vector<vector<int>>{{tmp[tmp.size()/2]}};
          else return vector<vector<int>>{{tmp[tmp.size()/2-1]}, {tmp.back()}};
        }
      }
    }; auto ret = DFS(1, N, false);
    if (ret.size() == 1) {
      for (auto x : ret[0]) ans.push_back({x+1, N});
    } else if (ret.size() == 2) ans.push_back({ret[0][0]+1, ret[1][0]});
    cout << ans.size() << "\n";
    for (auto& [L, R] : ans) cout << L << " " << R << "\n";
  }
  
  return 0;
}
