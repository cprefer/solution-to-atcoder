#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  vector<int> c(2);
  c[s[0] - 'A'] += 1;
  for (int i = 1; i <= n; i += 1) {
    c[s[i] - 'A'] += 1;
    cout << (c[0] >= c[1] ? "Alice\n" : "Bob\n");
  }
}