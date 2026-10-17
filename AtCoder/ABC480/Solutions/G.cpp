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

	int N; cin >> N; SegTree ST(N+1);
	vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
	stack<int> st1, st2; st1.push(0), st2.push(0);
	vector<int> dp(N+1);
	for (int i = 1; i <= N; i++) {
		while (st1.top() && A[st1.top()] <= A[i]) {
			int last = st1.top(); st1.pop();
			ST.Operate(st1.top()+1, last, -A[last]);
		}
		while (st2.top() && A[st2.top()] >= A[i]) {
			int last = st2.top(); st2.pop();
			ST.Operate(st2.top()+1, last, +A[last]);
		}
		ST.Operate(st1.top()+1, i, +A[i]);
		ST.Operate(st2.top()+1, i, -A[i]);
		st1.push(i); st2.push(i);
		if (i > 1) dp[i] = ST.Get(1, i-1);
		else dp[i] = 1e9+100;
		ST.Operate(i+1, i+1, dp[i]);
	}
	cout << dp[N] << "\n";

	return 0;
}