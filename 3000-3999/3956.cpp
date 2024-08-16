#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
#define f first
#define s second
#define sz(x) int((x).size())
int N, ans, eq;
vector<pi> cows;
void solve() {
  sort(begin(cows), end(cows));
  for (int a = 0; a < N; ++a) {
    set<int> sorted_y;
    for (int b = a + 1; b < N; ++b) {
      if (a < b - 1) sorted_y.insert(cows[b - 1].s);
      int len = cows[b].f - cows[a].f;
      int lo = max(cows[a].s, cows[b].s) - len, hi = min(cows[a].s, cows[b].s);
      if (lo > hi) continue;
      vector<int> y(begin(sorted_y), end(sorted_y));
      int l = 0, r = -1;
      while (l < sz(y) && lo >= y[l] + 1) l++;
      while (r + 1 < sz(y) && lo >= y[r + 1] - len) r++;
      while (true) {
        ++ans;
        int yl = min(cows[a].s, cows[b].s), yr = max(cows[a].s, cows[b].s);
        if (l <= r) yl = min(yl, y[l]), yr = max(yr, y[r]);
        assert(yr - yl <= len);
        eq += yr - yl == len;
        int leave_bottom = (l < sz(y) ? y[l] + 1 : INT_MAX);
        int enter_top = (r + 1 < sz(y) ? y[r + 1] - len : INT_MAX);
        int change_y = min(leave_bottom, enter_top);
        if (change_y > hi) break;
        l += leave_bottom == change_y;
        r += enter_top == change_y;
      }
    }
  }
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
  cin >> N;
  cows.resize(N);
  for (pi& cow : cows) cin >> cow.f >> cow.s;
  ans = N + 1;
  solve();
  for (pi& cow : cows) swap(cow.f, cow.s);
  solve();
  assert(eq % 2 == 0);
  cout << ans - eq / 2;
}
