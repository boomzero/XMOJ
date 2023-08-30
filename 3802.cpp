#include <bits/stdc++.h>
using namespace std;
int n, m, ans, pla;
int dp[21000][10][5];
int b[210], c[210][210];
void solve()
{
	int pos = 0;
	for (int i = 0; i <= m; ++i)
		dp[0][i][0] = 1;
	for (int i = 1; i * i <= n; ++i)
	{
		pla = i;
		for (int j = min(m, n / (i * i)); j >= 1; --j)
		{
			for (int k = n; k >= j * i * i; --k)
			{
				for (int kk = m; kk >= j; --kk)
				{
					dp[k][kk][i % 2] += dp[k - j * i * i][kk - j][(i - 1) % 2] * c[kk - j][kk];
					// cout<<i<<" "<<j<<" "<<k<<" "<<kk<<" "<<dp[k][kk][i%2]<<" "<<dp[k-j*i*i][kk-j][(i-1)%2]<<endl;
				}
			}
		}
		for (int k = n; k >= 0; --k)
		{
			for (int kk = m; kk >= 0; --kk)
			{
				dp[k][kk][i % 2] += dp[k][kk][(i - 1) % 2];
				dp[k][kk][(i - 1) % 2] = 0;
				// cout<<i<<" "<<k<<" "<<kk<<" "<<dp[k][kk][i%2]<<endl;
			}
		}
	}
}
signed main()
{
	freopen("puzzle.in", "r", stdin);
	freopen("puzzle.out", "w", stdout);
	cin >> n >> m;
	b[0] = 1;
	for (int i = 1; i <= m * 2; ++i)
	{
		b[i] = b[i - 1] * i;
		// cout<<i<<" "<<b[i]<<endl;
	}
	for (int i = 0; i <= m * 2; ++i)
	{
		for (int j = max(i, 1); j <= m * 2; ++j)
		{
			int x = i % j;
			c[i][j] = b[j] / (b[j - x] * b[x]);
			// cout<<i<<" "<<x<<" "<<j<<" "<<c[i][j]<<endl;
		}
	}
	solve();
	cout << dp[n][m][pla % 2] << endl;
}
