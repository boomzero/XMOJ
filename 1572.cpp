#include <iostream>

#include <algorithm>

#include <cmath>

using namespace std;

int tot, head[400], nxt[400], ver[400], dp[400][400], n, m, s[400];

void addedge(int u, int v)
{

	ver[++tot] = v;

	nxt[tot] = head[u];

	head[u] = tot;
}

void dfs(int u)
{

	dp[u][0] = 0;

	for (int i = 1; i < m; i++)
		dp[u][i] = s[u];

	for (int i = head[u]; i; i = nxt[i])
	{

		int v = ver[i];

		dfs(v);

		for (int j = m; j >= 1; j--)
		{

			for (int k = j - 1; k >= 0; k--)
			{

				dp[u][j] = max(dp[u][j], dp[v][k] + dp[u][j - k]);
			}
		}
	}
}

int main()
{

	cin >> n >> m;

	int u;

	for (int i = 1; i <= n; i++)
	{

		cin >> u >> s[i];

		addedge(u, i);
	}

	m++;

	dfs(0);

	cout << dp[0][m];

	return 0;
}
