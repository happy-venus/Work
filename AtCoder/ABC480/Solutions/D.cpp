#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, Q; cin >> N >> Q;
	vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
	vector<int> pre(N+1); for (int i = 1; i <= N; i++) pre[i] = pre[i-1] + A[i];
	vector<int> pos(N+1); for (int i = 1; i <= N; i++) pos[i] = pos[i-1] + pre[i];
	auto Get = [&](int x) {
		int st = 0, ed = N;
		while (st < ed) {
			int md = (st + ed) / 2;
			if (x >= (md+1) * (md+2) / 2) st = md+1;
			else ed = md;
		}
		return pos[st] + pre[x-st*(st+1)/2];
	};
	while (Q--) {
		int L, R; cin >> L >> R;
		cout << Get(R) - Get(L-1) << "\n";
	}

	return 0;
}