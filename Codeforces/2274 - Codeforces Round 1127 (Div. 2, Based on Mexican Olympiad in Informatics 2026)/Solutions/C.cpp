#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    int st = 1, ed = N;
    while (st < ed) {
      int md = (st + ed) / 2;
      long long len = 0;
      for (int i = md; i >= 1; i--) len += (md / i) * i;
      if (len >= N) ed = md;
      else st = md+1;
    }
    vector<int> arr(N+1);
    for (int i = st, cur = 1; i >= 1 && cur <= N; i--) {
      for (int j = i; j <= st && cur <= N; j += i) {
        arr[cur] = 1;
        cur += i;
      }
    }
    for (int i = 1; i <= N; i++) arr[i] += arr[i-1];
    cout << st << "\n";
    for (int i = 1; i <= N; i++) cout << arr[i] << " \n"[i == N];
  }
  
  return 0;
}
