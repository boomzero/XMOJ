#include <iostream>
#include <cstdio>
#include <cstring>
#define N 51
#define M 2510
using namespace std;
int num, length, all, color[N], dp[N][N][2], ans[M];
template <typename T>
void read(T &a)
{
	a = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	do
	{
		a = a * 10 + ch - '0';
		ch = getchar();
	} while ('0' <= ch && ch <= '9');
	a *= f;
}
int main()
{
	freopen("stage.in", "r", stdin);
	freopen("stage.out", "w", stdout);
	scanf("%d%d%d", &num, &length, &all);
	for (register int n = 1; n <= num; n++)
	{
		for (register int i = 1; i <= length; i++)
			scanf("%1d", &color[i]);
		memset(dp, 0, sizeof(dp));
		for (register int i = 1; i <= length; i++)
		{
			for (register int j = 1; j <= i; j++)
			{
				dp[i][j][color[i]] = dp[i - 1][j][color[i]] + 1;
				dp[i][j][!color[i]] = dp[i - 1][j][!color[i]];
				int tmax = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]);
				dp[i][j][color[i]] = max(dp[i][j][color[i]], tmax + 1);
				dp[i][j][!color[i]] = max(dp[i][j][!color[i]], tmax);
			}
		}
		for (register int i = all; i >= 1; i--)
			for (register int j = 0; j <= min(length, i); j++)
				ans[i] = max(ans[i], ans[i - j] + max(dp[length][j][0], dp[length][j][1]));
	}
	printf("%d", ans[all]);
	return 0;
}
