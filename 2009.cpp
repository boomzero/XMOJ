#include <iostream>

#include <cstdio>

#include <algorithm>

#include <cstring>

#include <cmath>

#include <string>

using namespace std;

int n, m, head[500005], dep[500005], fa[500005][21], cnt;

struct edge
{

	int to, next;

} e[1000005];

void add(int u, int v)
{

	e[++cnt].to = v;

	e[cnt].next = head[u];

	head[u] = cnt;
}

void dfs(int now, int pre)
{

	dep[now] = dep[pre] + 1;

	fa[now][0] = pre;

	for (int i = 1; i <= 20; i++)

		fa[now][i] = fa[fa[now][i - 1]][i - 1];

	for (int i = head[now]; i; i = e[i].next)

		if (e[i].to != pre)

			dfs(e[i].to, now);
}

int lca(int x, int y)
{

	if (dep[x] < dep[y])
		swap(x, y);

	for (int i = 20; i >= 0; i--)

		if (dep[fa[x][i]] >= dep[y])

			x = fa[x][i];

	if (x == y)
		return x;

	for (int i = 20; i >= 0; i--)

		if (fa[x][i] != fa[y][i])

			x = fa[x][i], y = fa[y][i];

	return fa[x][0];
}

signed main()
{

	cin >> n >> m;

	for (int i = 1; i < n; i++)

	{

		int u, v;

		scanf("%d%d", &u, &v);

		add(u, v), add(v, u);
	}

	dfs(1, 0);

	for (int i = 1; i <= m; i++)

	{

		int x, y, z, LCA[3];

		scanf("%d%d%d", &x, &y, &z);

		LCA[0] = lca(x, y), LCA[1] = lca(y, z), LCA[2] = lca(x, z);

		int id = LCA[0];

		if (dep[id] < dep[LCA[1]])
			id = LCA[1];

		if (dep[id] < dep[LCA[2]])
			id = LCA[2];

		printf("%d %d\n", id, dep[x] + dep[y] + dep[z] - (dep[LCA[0]] + dep[LCA[1]] + dep[LCA[2]]));
	}

	return 0;
}
