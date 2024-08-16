#include <bits/stdc++.h>
using namespace std;
const int MAXN = 60010;
vector<int> g[MAXN];
int dp[MAXN];
bool vis[MAXN];
int ans[MAXN], len, n;
void dfs(int x, int to)
{
	dp[x] = 1;
	bool flag = true;
	for (int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		if (!vis[y])
		{
			vis[y] = true;
			dfs(y, x);
			dp[x] += dp[y];
			if (dp[y] > n / 2)
			{
				flag = false;
			}
		}
	}
	if (n - dp[x] > n / 2)
	{
		flag = false;
	}
	if (flag)
	{
		ans[++len] = x;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	sort(ans + 1, ans + 1 + len);
	for (int i = 1; i <= len; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
