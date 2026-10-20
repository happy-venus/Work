#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, K; cin >> N >> K;
  vector<vector<int>> ans;
  vector<int> arr;
  function<void(int, int)> DFS = [&](int cur, int sum) {
    if (cur == 1) {
      ans.push_back(arr);
      ans.back().push_back(sum);
      reverse(ans.back().begin(), ans.back().end());
      return;
    }
    for (int i = 0; i <= sum; i += cur) {
      arr.push_back(i/cur);
      DFS(cur-1, sum-i);
      arr.pop_back();
    }
  }; DFS(N, K);
  sort(ans.begin(), ans.end());
  for (auto& arr : ans) {
    for (auto& x : arr) cout << x << " ";
    cout << "\n";
  }
  
  return 0;
}
