#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int eatleft[maxn], dp[maxn][maxn], n;
int main()
{
	freopen("snack.in", "r", stdin);
	freopen("snack.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &eatleft[i]);
	for (int i = 1; i <= n; i++)
		dp[i][i] = n * eatleft[i];
	for (int len = 2; len <= n; len++)
		for (int i = 1; i <= n; i++)
		{
			int j = i + len - 1, num = (i - 1) + (n - j) + 1;
			if (j <= n)
				dp[i][j] = max(dp[i + 1][j] + eatleft[i] * num, dp[i][j - 1] + eatleft[j] * num);
		}
	printf("%d", dp[1][n]);
	return 0;
}
