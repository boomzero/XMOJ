#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int SZ = 500;

const int mod = 998244353;

int dp[SZ][SZ];

int sum[SZ][SZ];

int getsum(int a, int b, int c, int d)

{

	return sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
}

int ask(int n)

{

	for (int i = 1; i <= n; i++)

		if (getsum(i, i, i, i))
			return 0;

	for (int i = n; i >= 1; i--)

	{

		dp[i][i] = 1;

		for (int j = i + 1; j <= n; j++)

		{

			if (!getsum(i, i + 1, i, j)) //(AB)

				dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;

			if (!getsum(i + 1, i, j, i)) //()AB

				dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;

			for (int k = i + 1; k < j; k++)

				if (!getsum(i, i + 1, i, k) && !getsum(k + 1, i, j, i) && !getsum(k + 1, i + 1, j, k))

					dp[i][j] = (dp[i][j] + (LL)dp[i + 1][k] * dp[k + 1][j] % mod) % mod;
		}
	}

	return dp[1][n];
}

void init()

{

	memset(dp, 0, sizeof(dp));

	memset(sum, 0, sizeof(sum));
}

int main()

{

	int T;

	scanf("%d", &T);

	while (T--)

	{

		init();

		int n, m;

		scanf("%d%d", &n, &m);

		for (int i = 1; i <= m; i++)

		{

			int x, y;

			scanf("%d%d", &x, &y);

			sum[x][y] = 1;
		}

		for (int i = 1; i <= n; i++)

			for (int j = 1; j <= n; j++)

				sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

		printf("%d\n", ask(n));
	}

	return 0;
}
