#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;
	vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];
	int S = accumulate(A.begin(), A.end(), 0LL) / M;
	vector<int> sum(1<<N);
	for (int i = 0; i < (1<<N); i++) {
		for (int j = 0; j < N; j++) if (i & (1<<j)) {
			sum[i] += A[j+1];
		}
	}
	vector<int> dp(1<<N); dp[0] = 0;
	for (int i = 1; i < (1<<N); i++) {
		for (int j = 0; j < N; j++) if (i & (1<<j)) {
			dp[i] = max(dp[i], dp[i-(1<<j)]);
		}
		dp[i] += (sum[i] % S == 0);
	}
	cout << M-dp.back() << "\n";

	return 0;
}