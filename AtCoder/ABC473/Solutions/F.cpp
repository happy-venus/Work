#include <bits/stdc++.h>
using namespace std;

struct SegTree {
	vector<int> segv, segf; int sz;
	SegTree(int N) {
		for (sz = 1; sz < N; sz *= 2);
		segv = segf = vector<int>(sz*2);
	}
	inline void Down(int i) {
		AddOP(i*2, segf[i]);
		AddOP(i*2+1, segf[i]);
		segf[i] = 0;
	}
	inline void AddOP(int i, int x) {
		segv[i] += x;
		segf[i] += x;
	}
	inline void Operate(int l, int r, int x, int i, int L, int R) {
		if (l == L && r == R) return AddOP(i, x);
		int md = (L + R) / 2; Down(i);
		if (r <= md) Operate(l, r, x, i*2, L, md);
		else if (l > md) Operate(l, r, x, i*2+1, md+1, R);
		else Operate(l, md, x, i*2, L, md), Operate(md+1, r, x, i*2+1, md+1, R);
		segv[i] = min(segv[i*2], segv[i*2+1]);
	}
	inline int Get(int l, int r, int i, int L, int R) {
		if (l == L && r == R) return segv[i];
		int md = (L + R) / 2; Down(i);
		if (r <= md) return Get(l, r, i*2, L, md);
		else if (l > md) return Get(l, r, i*2+1, md+1, R);
		else return min(Get(l, md, i*2, L, md), Get(md+1, r, i*2+1, md+1, R));
	}
	inline void Operate(int l, int r, int x) { return Operate(l, r, x, 1, 1, sz); }
	inline int Get(int l, int r) { return Get(l, r, 1, 1, sz); }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N; cin >> N;
  string S; cin >> S;
  SegTree ST(N+1);
  for (int i = 0; i < N; i++) ST.Operate(i+2, N+1, S[i] == 'A' ? +1 : -1);
  int Q; cin >> Q;
  while (Q--) {
    int type; cin >> type;
    if (type == 1) {
      int i; char c; cin >> i >> c;
      ST.Operate(i+1, N+1, S[i-1] == 'A' ? -1 : +1);
      S[i-1] = c;
      ST.Operate(i+1, N+1, S[i-1] == 'A' ? +1 : -1);
    } else {
      int L, R; cin >> L >> R;
      cout << (ST.Get(L, R+1) >= ST.Get(L, L) ? "Yes\n" : "No\n");
    }
  }
  
  return 0;
}
