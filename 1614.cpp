#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int nx, ny, vis[MAXN], match[MAXN];
vector<int> g[MAXN];
bool find(int x)
{
	for (int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		if (!vis[y])
		{
			vis[y] = true;
			if (match[y] < 0 || find(match[y]))
			{
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d%d", &nx, &ny);
	//	freopen(".in","r",stdin);
	//	freopen(".out","w",stdout);
	int ans = 0;
	memset(match, -1, sizeof match);
	for (int i = 1; i <= nx; i++)
	{
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; j++)
		{
			int k;
			scanf("%d", &k);
			g[i].push_back(k);
		}
	}
	for (int i = 1; i <= nx; i++)
	{
		memset(vis, 0, sizeof vis);
		if (find(i))
			ans++;
	}
	printf("%d", ans);
	return 0;
}
