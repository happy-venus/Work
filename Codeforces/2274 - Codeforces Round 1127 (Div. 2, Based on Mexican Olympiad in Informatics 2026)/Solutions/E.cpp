#include <bits/stdc++.h>
using namespace std;

struct BIT2D {
  vector<vector<int>> bit; int sz;
  BIT2D(int N) : bit(N+1, vector<int>(N+1)), sz(N) {}
  inline void Add(int i, int j, int v) {
    for (int x = i; x <= sz; x += (x & (-x))) {
      for (int y = j; y <= sz; y += (y & (-y))) {
        bit[x][y] += v;
      }
    }
  }
  inline int Get(int i, int j) {
    int r = 0;
    for (int x = i; x; x -= (x & (-x))) {
      for (int y = j; y; y -= (y & (-y))) {
        r += bit[x][y];
      }
    }
    return r;
  }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N, Q; cin >> N >> Q;
    vector<vector<int>> A(N+1, vector<int>(N+1));
    vector<vector<int>> B(N+1, vector<int>(N+1));
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> A[i][j];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> B[i][j];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) A[i][j] -= B[i][j];
    vector<vector<int>> arr(N, vector<int>(N)), sum(N, vector<int>(N));
    for (int i = 1; i < N; i++) {
      for (int j = 1; j < N; j++) {
        arr[i][j] = A[i][j] + A[i+1][j+1] - A[i+1][j] - A[i][j+1];
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (arr[i][j] != 0);
      }
    }
    BIT2D bit(N);
    while (Q--) {
      char type; cin >> type;
      if (type == 'U') {
        int r1, c1, r2, c2, x; cin >> r1 >> c1 >> r2 >> c2 >> x;
        if (r1 > 1 && c1 > 1) {
          if (arr[r1-1][c1-1] != 0) bit.Add(r1-1, c1-1, -1);
          arr[r1-1][c1-1] += x;
          if (arr[r1-1][c1-1] != 0) bit.Add(r1-1, c1-1, +1);
        }
        if (r1 > 1 && c2 < N) {
          if (arr[r1-1][c2] != 0) bit.Add(r1-1, c2, -1);
          arr[r1-1][c2] -= x;
          if (arr[r1-1][c2] != 0) bit.Add(r1-1, c2, +1);
        }
        if (r2 < N && c1 > 1) {
          if (arr[r2][c1-1] != 0) bit.Add(r2, c1-1, -1);
          arr[r2][c1-1] -= x;
          if (arr[r2][c1-1] != 0) bit.Add(r2, c1-1, +1);
        }
        if (r2 < N && c2 < N) {
          if (arr[r2][c2] != 0) bit.Add(r2, c2, -1);
          arr[r2][c2] += x;
          if (arr[r2][c2] != 0) bit.Add(r2, c2, +1);
        }
      } else {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        int delta = bit.Get(r2-1, c2-1) + bit.Get(r1-1, c1-1) - bit.Get(r1-1, c2-1) - bit.Get(r2-1, c1-1);
        int first = sum[r2-1][c2-1] + sum[r1-1][c1-1] - sum[r1-1][c2-1] - sum[r2-1][c1-1];
        cout << (first + delta ? "No\n" : "Yes\n");
      }
    }
  }
  
  return 0;
}
