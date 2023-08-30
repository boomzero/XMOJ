#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

int Map[120][12], state[120][100], num[120], dp[120][100][100];

int n, m, i, j, k, l;

char str[120][12];

int sum(int x, int m)

{

	int temp = 0, i;

	for (i = 0; i < m; i++)

		if ((1 << i) & x)

			temp++;

	return temp;
}

int main()

{

	scanf("%d%d", &n, &m);

	memset(dp, 0, sizeof(dp));

	memset(num, 0, sizeof(num));

	for (i = 1; i <= n; i++)

		scanf("%s", str[i]);

	for (i = 1; i <= n; i++)

		for (j = 0; j < m; j++)
		{

			if (str[i][j] == 'P')

				Map[i][j] = 1;

			else

				Map[i][j] = 0;
		}

	num[0] = 1;

	state[0][0] = 0;

	int x = 1 << m;

	for (i = 1; i <= n; i++)
	{

		for (j = 0; j < x; j++)
		{

			if (!(j & (j << 1)) && !(j & (j << 2)))
			{

				for (k = 0; k < m; k++)
				{

					if (!Map[i][k] && (j & 1 << k) > 0)

						break;
				}

				if (k == m)

					state[i][num[i]++] = j;
			}
		}
	}

	for (i = 0; i < num[1]; i++)
	{

		dp[1][i][0] = sum(state[1][i], m);
	}

	for (i = 2; i <= n; i++)

		for (j = 0; j < num[i]; j++)

			for (k = 0; k < num[i - 1]; k++)
			{

				if (state[i - 1][k] & state[i][j])

					continue;

				for (l = 0; l < num[i - 2]; l++)

				{

					if (state[i - 2][l] & state[i][j])

						continue;

					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l]);
				}

				dp[i][j][k] += sum(state[i][j], m);
			}

	int ans = 0;

	for (i = 0; i <= num[n]; i++)

		for (j = 0; j < num[n - 1]; j++)

			ans = max(ans, dp[n][i][j]);

	printf("%d", ans);

	return 0;
}
