#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N; cin >> N;
  string S = "UUD";
  for (int i = 1; i < N; i++) S += "LRL";
  for (int i = 3; i < N; i++) S += string(N-2, 'U') + "DU";
  S += "L";
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      int U = 1, D = N, rem = 3, last = -1;
      vector<string> pan(N, string(N, '1'));
      while (D-U+1 > 3 && U < r) last = U++;
      if (D-U+1 > 3 && D > r && U > 1) pan[last-1][0] = '0';
      while (D-U+1 > 3 && D > r) last = D--, rem = 2;
      if (rem == 3) {
        // first action L
        if (c < N) {
          // change to R
          if (c == 1) {
            if (last != -1) pan[last-1].back() = '0';
          } // no action L
          else pan[D-1][c-2] = '0'; // last action L
          last = c+1; rem--;
        } else last = c-1;
      } else {
        // first action R
        if (c > 1) {
          // change to L
          if (c == N) {
            if (last != -1) pan[last-1].back() = '0';
          }
          else pan[D-1][c] = '0';
          last = c-1; rem--;
        } else last = c+1;
      }
      if (r == D) {
        // action must be UU rem >= 2
        assert(rem >= 2);
        for (int i = U; i <= D && rem > 2; i++, rem--) pan[i-1][last-1] = '0';
        pan[U][c-1] = pan[U-1][c-1] = '0';
      } else if (r == U) {
        // action must be DD rem >= 1
        assert(rem >= 1);
        for (int i = U; i <= D && rem > 1; i++, rem--) pan[i-1][last-1] = '0';
        pan[D-1][c-1] = '0';
      } else {
        // action must be DU rem >= 1
        assert(rem >= 1);
        for (int i = U; i <= D && rem > 1; i++, rem--) pan[i-1][last-1] = '0';
        pan[U-1][c-1] = '0';
      }
      for (auto& row : pan) cout << row << "\n";
      cout << "\n";
    }
  }
  cout << S << "\n";
  
  return 0;
}
