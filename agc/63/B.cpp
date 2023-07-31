#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using i64 = int64_t;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> stack;
  i64 ans = 0;
  for (int i = 0, a; i < n; i += 1) {
    cin >> a;
    if (a == 1) {
      stack.push_back(1);
    } else {
      while (not stack.empty() and stack.back() + 1 != a) {
        stack.pop_back();
      }
      if (not stack.empty()) {
        stack.back() = a;
      }
    }
    ans += stack.size();
  }
  cout << ans;
}