#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
    int mi = max_element(A.begin()+1, A.end()) - A.begin();
    int xi = min_element(A.begin()+1, A.end()) - A.begin();
    if (A[xi] == A[mi]) cout << A[mi] << "\n";
    else {
      int b = 31 - __builtin_clz(A[xi]^A[mi]);
      cout << (A[mi]|((1<<b)-1)) << "\n";
    }
  }
  
  return 0;
}
