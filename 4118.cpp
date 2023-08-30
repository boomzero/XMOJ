#include <bits/stdc++.h>
using namespace std;
int n, a[1010], b[1010], ans, dp[1010][1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seg.in", "r", stdin);
	freopen("seg.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 0, dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//			cout<<a[i]<<" "<<b[j]<<" i="<<i<<" j="<<j<<endl;
			if (abs(a[i] - b[j]) <= 4)
				dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1] + 1));
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			//			cout<<endl;
		}
		//		cout<<endl;
	}
	printf("%d", dp[n][n]);
}
