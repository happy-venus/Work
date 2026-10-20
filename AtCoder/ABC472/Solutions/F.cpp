#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, Q; cin >> N >> Q;
  vector<int> X(N+1), Y(N+1);
  for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
  for (int i = 1; i <= N; i++) X.push_back(X[i]), Y.push_back(Y[i]);
  vector<pair<float, float>> ans(Q+1);
  auto GetTri = [&](int a, int b, int c) {
    int area = llabs((X[b]-X[a])*(Y[b]+Y[a])+(X[c]-X[b])*(Y[c]+Y[b])+(X[a]-X[c])*(Y[a]+Y[c]));
    int cx = (X[a]+X[b]+X[c]);
    int cy = (Y[a]+Y[b]+Y[c]);
    return array<int, 3>{cx, cy, area};
    // 10**12 * 2 * 1.5 * 10**6
  };
  vector<int> sumx(2*N), sumy(2*N), sum(2*N);
  function<void(int, int, vector<array<int, 3>>)> DFS = [&](int L, int R, vector<array<int, 3>> queries) {
    if (queries.empty()) return;
    int md = (L + R) / 2;
    vector<array<int, 3>> queryL, queryR;
    for (int i = md-1; i <= md+1; i++) sumx[i] = sumy[i] = sum[i] = 0;
    for (int i = md+2; i <= R; i++) {
      auto [cx, cy, area] = GetTri(md, i-1, i);
      sumx[i] = sumx[i-1] + cx * area;
      sumy[i] = sumy[i-1] + cy * area;
      sum[i] = sum[i-1] + area;
    }
    for (int i = md-2; i >= L; i--) {
      auto [cx, cy, area] = GetTri(md, i+1, i);
      sumx[i] = sumx[i+1] + cx * area;
      sumy[i] = sumy[i+1] + cy * area;
      sum[i] = sum[i+1] + area;
    }
    for (auto& [l, r, q] : queries) {
      if (r <= md) queryL.push_back({l, r, q});
      else if (l >= md) queryR.push_back({l, r, q});
      else {
        // l < md < r
        assert(l < md && md < r);
        int sx = sumx[l] + sumx[r];
        int sy = sumy[l] + sumy[r];
        int area = sum[l] + sum[r];
        auto [cx, cy, carea] = GetTri(md, l, r);
        sx += cx * carea;
        sy += cy * carea;
        area += carea;
        ans[q] = {static_cast<float>(sx) / static_cast<float>(area*3), static_cast<float>(sy) / static_cast<float>(area*3)};
      }
    }
    DFS(L, md, queryL); DFS(md, R, queryR);
  };
  vector<array<int, 3>> queries;
  for (int i = 1; i <= Q; i++) {
    int u, v; cin >> u >> v;
    if (v < u) v += N;
    queries.push_back({u, v, i});
  }
  DFS(1, 2*N-1, queries);
  for (int i = 1; i <= Q; i++) cout << fixed << setprecision(20) << ans[i].first << " " << ans[i].second << "\n";
  
  return 0;
}
