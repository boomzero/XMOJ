#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) +
			(x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
// #define mo
#define N 2010
// #define M
int n, m, i, j, k;
int ap[N], bp[N], as[N], bs[N];
int dp[N][N], ans, w, mx;
pair<int, int> p;
deque<pair<int, int>> q1, q2;

signed main()
{
	memset(dp, 0x80, sizeof(dp));
	n = read();
	m = read();
	w = read();
	for (i = 1; i <= n; ++i)
	{
		ap[i] = read();
		bp[i] = read();
		as[i] = read();
		bs[i] = read();
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 0; j <= m; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			if (j <= as[i])
				dp[i][j] = max(dp[i][j], -j * ap[i]);
		}
		if (i <= w)
			continue;
		for (j = 0; j <= m; ++j)
		{
			while (!q1.empty() && q1.front().second < j - as[i])
				q1.pop_front();
			while (!q1.empty() && q1.back().first <= dp[i - w - 1][j - 1] + (j - 1) * ap[i])
				q1.pop_back();
			p.first = dp[i - w - 1][j - 1] + (j - 1) * ap[i];
			p.second = j - 1;
			q1.push_back(p);
			dp[i][j] = max(dp[i][j], q1.front().first - j * ap[i]);
		}
		for (j = m; j >= 0; --j)
		{
			while (!q2.empty() && q2.front().second > j + bs[i])
				q2.pop_front();
			while (!q2.empty() && q2.back().first <= dp[i - w - 1][j + 1] + (j + 1) * bp[i])
				q2.pop_back();
			p.first = dp[i - w - 1][j + 1] + (j + 1) * bp[i];
			p.second = j + 1;
			q2.push_back(p);
			dp[i][j] = max(dp[i][j], q2.front().first - j * bp[i]);
		}
		q1.clear();
		q2.clear();
	}
	for (i = 0; i <= m; ++i)
		ans = max(ans, dp[n][i]);
	printf("%lld", ans);
	return 0;
}
