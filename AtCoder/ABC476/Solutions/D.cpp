#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, M, K; cin >> N >> M >> K;
  int X, Y; cin >> X >> Y;
  vector<int> A(N+1), B(M+1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= M; i++) cin >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  for (int i = 1; i <= N; i++) A[i] += A[i-1];
  int ans = upper_bound(A.begin(), A.end(), X+Y*K) - A.begin() - 1;
  for (int i = 1, cur = 0, rem = 0; i <= M; i++) {
    int c = (B[i] + K - 1) / K;
    int r = c * K - B[i];
    cur += c; rem += r;
    if (cur <= Y) {
      ans = max(ans, i + (upper_bound(A.begin(), A.end(), X+rem+(Y-cur)*K) - A.begin() - 1));
    }
  }
  cout << ans << "\n";
  
  return 0;
}
