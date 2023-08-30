#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
typedef long long ll;
ll head[maxn], len = 0, ans[maxn], siz[maxn], maxx;
int n, flag;
struct Edge
{
	int next, to;
} edge[maxn << 1];
inline void add(int u, int v)
{
	edge[++len].to = v;
	edge[len].next = head[u];
	head[u] = len;
}
inline void dfs1(int u, int fa, int dep)
{
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].next)
	{
		int v = edge[i].to;
		if (v == fa)
			continue;
		dfs1(v, u, dep + 1);
		siz[u] += siz[v];
		ans[1] += dep + 1;
	}
}
inline void dfs2(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].next)
	{
		int v = edge[i].to;
		if (v == fa)
			continue;
		ans[v] = ans[u] + n - 2 * siz[v];
		if (ans[v] > maxx)
		{
			maxx = ans[v];
			flag = v;
		}
		else if (ans[v] == maxx && flag > v)
		{
			flag = v;
		}
		dfs2(v, u);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dfs1(1, 0, 0);
	maxx = ans[1], flag = 1;
	dfs2(1, 0);
	printf("%d", flag);
	return 0;
}
