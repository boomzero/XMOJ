#include <bits/stdc++.h>
using namespace std;
const int mac = 5e5 + 10;
const int inf = 1e9 + 10;
vector<pair<int, int>> g[mac];
int dis[mac], d = 0, pt, st, ed;
int fa[mac], vis[mac];
void dfs(int x, int fa1)
{
	fa[x] = fa1;
	for (auto v : g[x])
	{
		if (v.first == fa1)
			continue;
		dis[v.first] = dis[x] + v.second;
		if (dis[v.first] >= d)
		{
			d = dis[v.first];
			pt = v.first;
		}
		dfs(v.first, x);
	}
}
int dfs_dist(int x, int fa)
{
	int dist = 0;
	for (auto v : g[x])
	{
		if (v.first == fa)
			continue;
		if (vis[v.first])
			continue;
		dist = max(dist, dfs_dist(v.first, x) + v.second);
	}
	return dist;
}
int main()
{
	int n, s;
	scanf("%d%d", &n, &s);
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	dfs(1, -1);
	memset(dis, 0, sizeof dis);
	st = pt;
	dfs(pt, -1);
	ed = pt;
	int ans = inf;
	for (int i = ed, j = ed; (i != -1) && (j != -1); j = fa[j])
	{
		while (dis[i] - dis[j] > s && i != -1)
			i = fa[i];
		ans = min(ans, max(dis[j], dis[ed] - dis[i]));
	} // 树状数组
	for (int i = ed; i != -1; i = fa[i])
		vis[i] = 1;
	for (int i = ed; i != -1; i = fa[i])
	{
		int p = dfs_dist(i, -1);
		ans = max(p, ans);
	}
	printf("%d", ans);
	return 0;
}
