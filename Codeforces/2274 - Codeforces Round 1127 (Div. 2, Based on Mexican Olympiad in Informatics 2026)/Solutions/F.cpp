#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int X = 1431;
    cout << X+1 << " " << 10000-2*X << endl;
    int v; cin >> v;
    if (v == 0) {
      for (int i = 1; i < 10; i++) {
        cout << X+1 << " " << 10000-2*X << endl;
        int v; cin >> v;
        assert(v == 0);
      }
    } else if (v <= X) {
      cout << X << " " << 10001-2*X << endl;
      int y; cin >> y;
      assert(abs(v-y) == 1);
      int a, b;
      if (y == v+1) a = X+y, b = 10001-2*X-y;
      else a = X-y, b = 10001-2*X+y;
      for (int i = 2; i < 10; i++) {
        cout << a << " " << b << endl;
        int v; cin >> v;
        assert(v == 0);
      }
    } else {
      vector<int> cands = {X+1+v, 10000-2*X-v, 10000-2*X+v};
      if (cands[0] >= cands[1]) {
        for (int i = 1; i < 10; i++) {
          cout << cands[0] << " " << cands[2] << endl;
          int v; cin >> v;
          assert(v == 0);
        }
      } else {
        int com = (cands[0] + cands[1]) / 2;
        cout << com << " " << cands[2] << endl;
        int y; cin >> y;
        if (y == 0) {
          for (int i = 2; i < 10; i++) {
            cout << com << " " << cands[2] << endl;
            int v; cin >> v;
            assert(v == 0);
          }
        } else {
          for (int i = 2; i < 10; i++) {
            cout << cands[0] << " " << cands[1] << endl;
            int v; cin >> v;
            assert(v == 0);
          }
        }
      }
    }
  }
  
  return 0;
}
