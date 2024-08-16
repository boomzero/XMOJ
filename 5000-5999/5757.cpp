#include <bits/stdc++.h>
using namespace std;
int n, ans, dp[2510][2510];
int main()
{
	scanf("%d", &n);
	dp[0][0] = 1;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= min(j, (n + 1) / 2 - 1); k++)
			{
				dp[i][j] += dp[i - 1][j - k];
			}
		}
	}
	printf("%d", dp[4][n]);
	return 0;
}
