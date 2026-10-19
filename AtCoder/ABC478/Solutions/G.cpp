#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int N, p, q; cin >> N >> p >> q;
  auto GetConvexHull = [&](vector<pair<int, int>> points) {
    auto Calc = [&](pair<int, int> x, pair<int, int> y, pair<int, int> z) {
      return 1LL*(y.first-x.first)*(z.second-y.second) > 1LL*(y.second-x.second)*(z.first-y.first);
    };
    sort(points.begin(), points.end());
    vector<pair<int, int>> conv = {points[0]};
    for (int round = 0; round < 2; round++) {
      conv.pop_back(); int c = conv.size(), s = 0;
      for (auto& p : points) {
        while (s >= 2 && !Calc(conv[c-2], conv[c-1], p)) conv.pop_back(), c--, s--;
        conv.push_back(p); c++; s++;
      }
      reverse(points.begin(), points.end());
    }
    return conv;
  };
  vector<pair<int, int>> points(N);
  for (auto& [x, y] : points) cin >> x >> y;
  vector<pair<int, int>> candidates;
  function<void(int, int)> DFS = [&](int L, int R) {
    if (L == R) return;
    int md = (L + R) / 2;
    auto conv1 = GetConvexHull(vector<pair<int, int>>{points.begin()+L, points.begin()+md+1});
    auto conv2 = GetConvexHull(vector<pair<int, int>>{points.begin()+md+1,points.begin()+R+1});
    int x = conv1[0].first*q+conv2[0].first*p, y = conv1[0].second*q+conv2[0].second*p;
    candidates.push_back({x, y});
    auto Get = [&](int c, int type) {
      auto& conv = (type ? conv2 : conv1);
      int dx = conv[c].first-conv[c-1].first;
      int dy = conv[c].second-conv[c-1].second;
      if (type == 1) dx *= p, dy *= p;
      else dx *= q, dy *= q;
      return make_pair(dx, dy);
    };
    auto GetSgn = [&](pair<int, int> x) {
      if (x.first == 0) return (x.second > 0 ? +1 : -1);
      else return (x.first > 0 ? +1 : -1);
    };
    auto Comp = [&](pair<int, int> x, pair<int, int> y) {
      int sx = GetSgn(x), sy = GetSgn(y);
      if (sx != sy) return sx > sy;
      return 1LL * x.first * y.second > 1LL * y.first * x.second;
    };
    for (int i = 1, j = 1; i < conv1.size() || j < conv2.size(); ) {
      pair<int, int> vec = Get(j, 1);
      if (j == conv2.size() || i < conv1.size() && Comp(Get(i, 0), vec)) vec = Get(i, 0), i++;
      else j++;
      x += vec.first, y += vec.second;
      candidates.push_back({x, y});
    }
    DFS(L, md); DFS(md+1, R);
  }; DFS(0, N-1);
  auto conv = GetConvexHull(candidates);
  long long num = 0, den = 2*(p+q)*(p+q);
  for (int i = 1; i < conv.size(); i++) {
    num += (conv[i].second+conv[i-1].second)*(conv[i].first-conv[i-1].first);
  }
  num = abs(num);
  int g = __gcd(num, den);
  cout << num / g << " " << den / g;
  
  return 0;
}
