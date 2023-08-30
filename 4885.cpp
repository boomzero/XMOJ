#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 510, mod = 1e9 + 7;

int n, k, dp[6][N][N];

char s[N];

bool pipei(int l, int r)
{

  return (s[l] == '(' || s[l] == '?') & (s[r] == ')' || s[r] == '?');
}

signed main()
{

  freopen("bracket.in", "r", stdin);

  freopen("bracket.out", "w", stdout);

  ios::sync_with_stdio(false);

  cin.tie(0);

  cout.tie(0);

  cin >> n >> k >> s + 1;

  for (int i = 1; i <= n; i++)
    dp[0][i][i - 1] = 1;

  for (int len = 1; len <= n; len++)
  {

    for (int l = 1; l + len - 1 <= n; l++)
    {

      int r = l + len - 1;

      if (len <= k)
        dp[0][l][r] = dp[0][l][r - 1] && (s[r] == '*' || s[r] == '?');

      if (len >= 2)
      {

        dp[1][l][r] = pipei(l, r) * (dp[2][l + 1][r - 1] + dp[3][l + 1][r - 1] + dp[4][l + 1][r - 1] + dp[0][l + 1][r - 1]) % mod;

        for (int i = l; i < r; i++)
        {

          (dp[2][l][r] += dp[3][l][i] * dp[0][i + 1][r]) %= mod;

          (dp[3][l][r] += (dp[2][l][i] + dp[3][l][i]) * dp[1][i + 1][r]) %= mod;

          (dp[4][l][r] += (dp[5][l][i] + dp[4][l][i]) * dp[1][i + 1][r]) %= mod;

          (dp[5][l][r] += dp[4][l][i] * dp[0][i + 1][r]) %= mod;
        }
      }

      (dp[5][l][r] += dp[0][l][r]) %= mod;

      (dp[3][l][r] += dp[1][l][r]) %= mod;
    }
  }

  cout << dp[3][1][n];
}
