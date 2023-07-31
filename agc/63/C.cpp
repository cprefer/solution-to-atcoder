#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using i64 = int64_t;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<i64, i64>> vp(n);
  i64 k = 0;
  for (auto &[a, _] : vp) {
    cin >> a;
  }
  for (auto &[_, b] : vp) {
    cin >> b;
    k = max(k, b + 1);
  }
  sort(vp.begin(), vp.end());
  for (int i = 1; i < n; i += 1) {
    if (vp[i].first == vp[i - 1].first and
        vp[i].second != vp[i - 1].second) {
      cout << "No";
      return 0;
    }
  }
  vp.erase(unique(vp.begin(), vp.end()), vp.end());
  n = vp.size();
  if (n == 1) {
    cout << "Yes\n1\n";
    cout << (vp[0].second - vp[0].first % k + k) % k << " "
         << k;
    return 0;
  }
  i64 sum_x = 0;
  cout << "Yes\n" << n << "\n";
  for (int i = n - 1; i; i -= 1) {
    i64 x = vp[(i + 1) % n].second - vp[i].second -
            (i == n - 1 ? vp[(i + 1) % n].first : 0);
    if (x <= 0) {
      x += (-x / k + 1) * k;
    }
    sum_x += x;
    i64 y = vp[i].first + sum_x;
    cout << x << " " << y << "\n";
  }
  i64 x = vp[1].second, y = k;
  cout << x << " " << y << "\n";
}