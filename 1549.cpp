#include <bits/stdc++.h>

using namespace std;

int n, w[1010], dp[1010][1010];

int main()
{

	cin >> n;

	for (int i = 0; i < n; ++i)

		cin >> w[i];

	memset(dp, 0x3f3f3f3f, sizeof(dp));

	for (int i = 0; i < n - 1; ++i)

		dp[i][i + 1] = 0;

	for (int l = 2; l < n; ++l)

		for (int i = 0, j = i + l; j < n; ++i, ++j)

			for (int k = i + 1; k < j; ++k)

				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + w[i] + w[j] + w[k]);

	cout << dp[0][n - 1];

	return 0;
}
