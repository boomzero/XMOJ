#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10010, maxm = 50010;
int n, m, q, fa[maxn], head[maxn], cnt, h[maxn], f[maxn][20], g[maxn][20], ans = 1000000000;
bool vis[maxn];
struct node
{
	int x, y, z;
} a[maxm];
struct node2
{
	int nextt, to, w;
} e[maxn * 2];
bool cmp(node a1, node b)
{
	return a1.z > b.z;
}
void dfs(int u, int depth)
{
	vis[u] = true;
	h[u] = depth;
	for (int i = head[u]; i; i = e[i].nextt)
		if (!vis[e[i].to])
		{
			f[e[i].to][0] = u;
			g[e[i].to][0] = e[i].w;
			dfs(e[i].to, depth + 1);
		}
	return;
}
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void add(int p, int q, int v)
{
	e[++cnt].to = q;
	e[cnt].nextt = head[p];
	head[p] = cnt;
	e[cnt].w = v;
}
void kruskal()
{
	sort(a + 1, a + 1 + m, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int fx = find(a[i].x), fy = find(a[i].y);
		if (fx == fy)
			continue;
		fa[fx] = fy;
		add(a[i].x, a[i].y, a[i].z);
		add(a[i].y, a[i].x, a[i].z);
	}
}
int lca(int a1, int b1)
{
	ans = 1000000000;
	if (a1 == b1)
		return 0;
	if (h[a1] < h[b1])
		swap(a1, b1);
	int k = int(log2(h[a1]));
	for (int i = k; i >= 0; i--)
		if (h[a1] - (1 << i) >= h[b1])
		{
			ans = min(ans, g[a1][i]);
			a1 = f[a1][i];
		}
	if (a1 == b1)
		return ans;
	for (int i = k; i >= 0; i--)
		if (f[a1][i] && f[a1][i] != f[b1][i])
		{
			ans = min(ans, min(g[a1][i], g[b1][i]));
			a1 = f[a1][i];
			b1 = f[b1][i];
		}
	ans = min(ans, min(g[a1][0], g[b1][0]));
	return ans;
}
int main()
{
	memset(vis, false, sizeof vis);
	memset(head, 0, sizeof head);
	memset(f, 0, sizeof f);
	memset(g, 0x3f2, sizeof g);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
	kruskal();
	scanf("%d", &q);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i, 1);
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			if (f[i][j - 1])
			{
				f[i][j] = f[f[i][j - 1]][j - 1];
				g[i][j] = min(g[i][j - 1], g[f[i][j - 1]][j - 1]);
			}
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (find(x) != find(y))
			printf("-1\n");
		else
			printf("%d\n", lca(x, y));
	}
	return 0;
}
