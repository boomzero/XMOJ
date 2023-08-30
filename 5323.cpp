#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll dp[110][110][110], ans;

int n, m;

inline ll change(ll x)
{

	return ((x * (x - 1) % 9999973) / 2) % 9999973;
}

int main()
{

	scanf("%d%d", &n, &m);

	dp[0][0][0] = 1;

	for (int i = 0; i < n; i++)

		for (int j = 0; j <= m; j++)

			for (int k = 0; j + k <= m; k++)
			{

				dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % 9999973;

				if (j >= 1 && (m - j - k >= 1))

					dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + (j * (m - j - k) % 9999973) * dp[i][j][k] % 9999973) % 9999973;

				if (j >= 2)

					dp[i + 1][j - 2][k + 2] = (dp[i + 1][j - 2][k + 2] + change(j) * dp[i][j][k] % 9999973) % 9999973;

				if (j >= 1)

					dp[i + 1][j - 1][k + 1] = (dp[i + 1][j - 1][k + 1] + j * dp[i][j][k] % 9999973) % 9999973;

				if (m - j - k >= 1)

					dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] + (m - j - k) * dp[i][j][k] % 9999973) % 9999973;

				if (m - j - k >= 2)

					dp[i + 1][j + 2][k] = (dp[i + 1][j + 2][k] + change(m - j - k) * dp[i][j][k] % 9999973) % 9999973;
			}

	for (int j = 0; j <= m; j++)

		for (int k = 0; j + k <= m; k++)

			ans = (ans + dp[n][j][k]) % 9999973;

	printf("%lld", ans);
}
