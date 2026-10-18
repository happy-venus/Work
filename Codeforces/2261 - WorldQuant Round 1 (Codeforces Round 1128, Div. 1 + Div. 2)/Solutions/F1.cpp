#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  vector<string> arr = {
    "111111001",
    "011111100",
    "110110110",
    "010111111",
    "111111111",
    "010111101",
    "111000110",
    "110101111",
    "011010111",
  };

  int N; cin >> N;
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      int tr = (r > 1) + (r == N);
      int tc = (c > 1) + (c == N);
      vector<string> pan(N, string(N, '1')); int cnt = 0;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          int ci = r + i - tr, cj = c + j - tc;
          pan[ci-1][cj-1] = arr[tr*3+tc][i*3+j];
          cnt += (arr[tr*3+tc][i*3+j] == '1');
        }
      }
      int U = r-tr, D = r-tr+2, L = c-tc, R = c-tc+2;
      if (U > 1) {
        U--; int cur = 3;
        for (int i = L; i <= R && (cnt + cur) % 4 != 1; i++, cur--) pan[U-1][i-1] = '0';
        cnt += cur;
      } else if (D < N) {
        D++; int cur = 3;
        for (int i = L; i <= R && (cnt + cur) % 4 != 0; i++, cur--) pan[D-1][i-1] = '0';
        cnt += cur;
      }
      // DULR
      while (L > 1) {
        int cur = D-U+1; L--;
        for (int i = U; i <= D && (cnt + cur) % 4 != 2; i++, cur--) pan[i-1][L-1] = '0';
        cnt += cur;
      }
      while (R < N) {
        int cur = D-U+1; R++;
        for (int i = U; i <= D && (cnt + cur) % 4 != 3; i++, cur--) pan[i-1][R-1] = '0';
        cnt += cur;
      }
      while (U > 1) {
        int cur = R-L+1; U--;
        for (int i = L; i <= R && (cnt + cur) % 4 != 1; i++, cur--) pan[U-1][i-1] = '0';
        cnt += cur;
      }
      while (D < N) {
        int cur = R-L+1; D++;
        for (int i = L; i <= R && (cnt + cur) % 4 != 0; i++, cur--) pan[D-1][i-1] = '0';
        cnt += cur;
      }
      assert(cnt >= N*N - 24);
      for (auto& row : pan) cout << row << "\n";
    }
  }
  string way = "DURLDULRDU";
  while (way.length() <= N*N) way += "LRDU";
  cout << way.substr(0, N*N+1) << "\n";
  
  return 0;
}