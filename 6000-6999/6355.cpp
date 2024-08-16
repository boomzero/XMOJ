#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
inline void read(int &x)
{
  char ch = getchar();
  int r = 0, w = 1;
  while (!isdigit(ch))
    w = ch == '-' ? -1 : 1, ch = getchar();
  while (isdigit(ch))
    r = (r << 1) + (r << 3) + (ch ^ 48), ch = getchar();
  x = r * w;
}
const int N = 1007, mod = 998244353;
int n, m, c, f, r[N][N], dn[N][N], sum[N][N], sum2[N][N];
char ok[N][N];
int getc()
{
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (dn[i][j] >= 3 && ok[i][j] == '0')
        ans = (ans + (r[i][j] - 1) * (sum[i + dn[i][j] - 1][j] - sum[i + 1][j]) % mod) % mod;
  return ans;
}
int getf()
{
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (dn[i][j] > 3 && ok[i][j] == '0')
        ans = (ans + (r[i][j] - 1) * (sum2[i + dn[i][j] - 2][j] - sum2[i + 1][j]) % mod) % mod;
  return ans;
}
void init()
{
  memset(r, 0, sizeof r);
  memset(dn, 0, sizeof dn);
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
      r[i][j] = ok[i][j] == '1' ? 0 : r[i][j + 1] + 1;
  for (int j = 1; j <= m; j++)
    for (int i = n; i >= 1; i--)
      dn[i][j] = ok[i][j] == '1' ? 0 : dn[i + 1][j] + 1;
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      sum[i][j] = sum[i - 1][j] + r[i][j] - 1;
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      sum2[i][j] = sum2[i - 1][j] + (r[i][j] - 1) * (dn[i][j] - 1);
}
void solve()
{
  read(n);
  read(m);
  read(c);
  read(f);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> ok[i][j];
  init();
  printf("%lld %lld\n", getc() * c, getf() * f);
}
main()
{
  freopen("plant.in", "r", stdin);
  freopen("plant.out", "w", stdout);
  int T, id;
  read(T);
  read(id);
  while (T--)
    solve();
  return 0;
}
