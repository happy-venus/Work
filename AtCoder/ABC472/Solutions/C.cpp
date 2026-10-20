#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, M, K; cin >> N >> M >> K;
  vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
  vector<int> calories(N+1);
  for (int i = 1; i <= N; i++) {
    if (calories[i-1] - calories[max(i-M, 0LL)] + A[i] <= K) {
      calories[i] = calories[i-1] + A[i];
      cout << "Yes\n";
    } else {
      cout << "No\n";
      calories[i] = calories[i-1];
    }
  }
  
  return 0;
}
