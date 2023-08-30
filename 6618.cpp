#include <stdio.h>

#include <algorithm>

using namespace std;

#define mod 1000000

int cnt[1005], sum[1005], dp[2][100005], sd[100005];

int main(void)

{

	int ans, n, m, a, b, x, i, j, k, y;

	scanf("%d%d%d%d", &n, &m, &a, &b);

	for (i = 1; i <= m; i++)

	{

		scanf("%d", &x);

		cnt[x]++;
	}

	for (i = 1; i <= n; i++)

		sum[i] = sum[i - 1] + cnt[i];

	dp[0][0] = 1;

	for (i = 0; i <= m; i++)

		sd[i] = 1;

	for (i = 1; i <= n; i++)

	{

		y = i & 1;

		for (j = 0; j <= sum[i]; j++)

		{

			dp[y][j] = ((sd[j] - sd[j - min(cnt[i], j) - 1]) % mod + mod) % mod;

			/*for(k=min(cnt[i],j);k>=0;k--)

			  dp[y][j] = (dp[y][j]+dp[y^1][j-k])%mod;*/
		}

		sd[0] = dp[y][0];

		for (j = 1; j <= m; j++)

			sd[j] = (sd[j - 1] + dp[y][j]) % mod;
	}

	ans = 0;

	for (i = a; i <= b; i++)

		ans = (ans + dp[n & 1][i]) % mod;

	printf("%d\n", ans);

	return 0;
}
