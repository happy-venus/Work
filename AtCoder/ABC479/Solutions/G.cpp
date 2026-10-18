#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  // (A+c) = (B+d) * x
  // A+c = Bx+dx
  // A-Bx = dx-c = f
  // min(abs(A-Bx), abs(B-A/x))
  int N; cin >> N;
  vector<int> A(N+1), B(N+1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= N; i++) cin >> B[i];
  vector<pair<long long, int>> ans;
  for (int round = 0; round < 2; round++) {
    for (int i = 1; i <= N; i++) if (B[i] < 0) A[i] = -A[i], B[i] = -B[i];
    vector<pair<int, int>> frac; long long res = 0;
    for (int i = 1; i <= N; i++) {
      if (B[i] == 0) res += abs(A[i]);
      else frac.push_back({A[i], B[i]});
    }
    sort(frac.begin(), frac.end(), [&](pair<int, int> f1, pair<int, int> f2) {
      return 1LL * f1.first * f2.second < 1LL * f2.first * f1.second;
    });
    long long sum = 0; for (int i = 1; i <= N; i++) sum -= B[i];
    auto Calc = [&](int a, int b) {
      // x - y * a / b
      long long num = 0;
      for (auto& [x, y] : frac) num += abs(1LL * x * b - 1LL * y * a);
      ans.push_back({num + res * b, b});
    };
    for (auto& [a, b] : frac) {
      sum += 2 * b;
      if (sum >= 0) {
        Calc(a, b);
        break;
      }
    }
    if (frac.empty()) ans.push_back({res, 1});
    swap(A, B);
  }
  sort(ans.begin(), ans.end(), [&](pair<long long, int> x, pair<long long, int> y) {
    return make_pair(x.first/x.second, 1LL*x.first%x.second*y.second) < make_pair(y.first/y.second, 1LL*y.first%y.second*x.second);
  });
  auto [num, den] = ans[0]; long long g = __gcd(num, (long long)den);
  cout << num / g << " " << den / g << "\n";
  
  return 0;
}
