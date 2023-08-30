#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

const int INF = 0x3f3f3f3f;

int n, k2, a[20][20], dp[1 << 20][20];

int main()
{

	cin >> n >> k2;

	for (int i = 0; i < n; ++i)

		for (int j = 0; j < n; ++j)

			cin >> a[i][j];

	memset(dp, INF, sizeof(dp));

	for (int i = 0; i < n; i++)
	{

		int k = 1;

		for (int j = 0; j < n; j++)
		{

			k *= 2;
		}

		dp[k][i] = k2;
	}

	int ans = INF;

	memset(dp, INF, sizeof(dp));

	for (int i = 0; i < n; ++i)

		dp[1 << i][i] = 0;

	for (int i = 0; i < (1 << n); ++i)

		for (int j = 0; j < n; ++j)

			if (dp[i][j] < INF)

				for (int k = 0; k < n; ++k)

					if (!(i & (1 << k)))

						dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + a[j][k]);

	for (int i = 0; i < n; ++i)

		ans = min(ans, dp[(1 << n) - 1][i]);

	cout << ans + k2;
}
