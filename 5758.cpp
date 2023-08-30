#include <iostream>
#include <cstdio>
using namespace std;
const int SZ = 1010;
struct Edge
{
	int f, t, d;
} es[SZ << 1];
int first[SZ << 1], nxt[SZ << 1], tot = 1;
int depth[SZ], fa[SZ], dis[SZ], jump[SZ][20];
inline void build(int f, int t, int d)
{
	es[++tot] = (Edge){f, t, d};
	nxt[tot] = first[f];
	first[f] = tot;
}
inline void dfs(int u, int f)
{
	depth[u] = depth[f] + 1;
	fa[u] = f;
	jump[u][0] = f;
	for (int i = 1; i <= 16; i++)
		jump[u][i] = jump[jump[u][i - 1]][i - 1];
	for (int i = first[u]; i; i = nxt[i])
	{
		int v = es[i].t;
		if (v == f)
			continue;
		dis[v] = dis[u] + es[i].d;
		dfs(v, u);
	}
}
inline int lca(int l, int r)
{
	if (depth[l] < depth[r])
		swap(l, r);
	int t = depth[l] - depth[r];
	for (int i = 0; i <= 16; i++)
		if (t & (1 << i))
			l = jump[l][i];
	for (int i = 16; i >= 0; i--)
		if (jump[l][i] != jump[r][i])
			l = jump[l][i], r = jump[r][i];
	if (l == r)
		return l;
	return jump[l][0];
	// maybe the problem is here(?
}
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	//	n=read(),q=read();
	int f, t, d;
	// 离散化？
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%d", &f, &t, &d);
		//		f=read(),t=read(),d=read();
		build(f, t, d);
		build(t, f, d); // maybe the build is wrong(?
		//		build(t,f,t);
	}
	dfs(1, 0);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &f, &t);
		//		f=read(),t=read();
		int F = lca(f, t);
		int ans = dis[f] + dis[t] - 2 * dis[F];
		printf("%d\n", ans);
	}
	return 0;
}
