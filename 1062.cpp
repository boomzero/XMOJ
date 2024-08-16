#include<bits/stdc++.h>
using namespace std;
int n, m, v, e;
const int N = 2005;
int ma[305][505];
int c[N][N];
double k[N];
double dp[N][N][2];
const double INF = 1e9;
int main()
{
	scanf("%d%d%d%d", &n, &m, &v, &e);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i][0]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i][1]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &k[i]);
	}
	memset(ma, 63, sizeof ma);
	for (int i = 1; i <= e; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		ma[u][v] = ma[v][u] = min(ma[u][v], w);
	}
	for (int k = 1; k <= v; k++)
	{
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				ma[i][j] = min(ma[i][j], ma[i][k] + ma[k][j]);
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		ma[i][i]  = 0;
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			dp[i][j][0] = dp[i][j][1] = INF;
		}
	}
	dp[1][0][0] = dp[1][1][1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0][0] = dp[i - 1][0][0] + ma[c[i - 1][0]][c[i][0]];
		for (int j = 1; j <= min(i, m); j++)
		{
			int o1 = c[i - 1][0], o2 = c[i - 1][1], o3 = c[i][0], o4 = c[i][1];
			dp[i][j][0] = min(dp[i - 1][j][0] + ma[o1][o3], dp[i - 1][j][1] + ma[o2][o3] * k[i - 1] + ma[o1][o3] * (1 - k[i - 1]));
			dp[i][j][1] = min(dp[i - 1][j - 1][0] + ma[o1][o4] * k[i] + ma[o1][o3] * (1 - k[i]), dp[i - 1][j - 1][1] + ma[o2][o3] * k[i - 1] * (1 - k[i]) + ma[o1][o3] * (1 - k[i - 1]) * (1 - k[i]) + ma[o1][o4] * (1 - k[i - 1]) * k[i] + ma[o2][o4] * k[i - 1] * k[i]);
		}		
	}
	double ans = INF;
	for (int i = 0; i <= m; i++)
	{
		ans = min(ans, min(dp[n][i][0], dp[n][i][1]));
	}
	printf("%.2lf", ans);
	return 0;
}
