#include <bits/stdc++.h>

using namespace std;

int dp[20][20], a[20][20], n, m, ans[20][20][20];

int main()

{

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= m; j++)

			scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; i++)

	{

		for (int j = 0; j <= m; j++)

		{

			for (int k = 0; k <= j; k++)

			{

				if (dp[i][j] <= dp[i - 1][j - k] + a[i][k])

				{

					dp[i][j] = dp[i - 1][j - k] + a[i][k];

					for (int l = 1; l < i; l++)
						ans[i][j][l] = ans[i - 1][j - k][l]; // 记录路径，如果状态转移了就更新之前所有的路径

					ans[i][j][i] = k;
				}
			}
		}
	}

	printf("%d\n", dp[n][m]);

	for (int i = 1; i <= n; i++)
		printf("%d %d\n", i, ans[n][m][i]);

	return 0;
}
