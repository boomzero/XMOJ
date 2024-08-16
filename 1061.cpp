#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
 
const int MAXN = 3e5;
struct Edge
{
	int to, nxt;
} e[MAXN * 2], e1[MAXN], e2[MAXN];
int n, m, w[MAXN], s[MAXN], t[MAXN], tot = -1, head[MAXN];
int fa[MAXN], siz[MAXN], son[MAXN], dep[MAXN] = {0};
int dfn[MAXN], rnk[MAXN], top[MAXN], cnt = 0;
int dist[MAXN], st[MAXN] = {0}, ans[MAXN] = {0};
int tot1 = -1, tot2 = -1, head1[MAXN], head2[MAXN];
int bu1[MAXN * 2], bu2[MAXN * 2];
void add(int x, int y)
{
	e[++tot].to = y;
	e[tot].nxt = head[x];
	head[x] = tot;
}
void add1(int x, int y)
{
	e1[++tot1].to = y;
	e1[tot1].nxt = head1[x];
	head1[x] = tot1;
}
void add2(int x, int y)
{
	e2[++tot2].to = y;
	e2[tot2].nxt = head2[x];
	head2[x] = tot2;
}
void input()
{
	memset(head, -1, sizeof(head));
	memset(head1, -1, sizeof(head1));
	memset(head2, -1, sizeof(head2));
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", w + i);
	for (int i = 1; i <= m; i++)
		scanf("%d %d", s + i, t + i);
}
void setup(int x, int fat)
{
	fa[x] = fat;
	siz[x] = 1, son[x] = -1;
	dep[x] = dep[fat] + 1;
	for (int i = head[x]; ~i; i = e[i].nxt)
	{
		int y = e[i].to;
		if (y == fat)
			continue;
		setup(y, x);
		siz[x] += siz[y];
		if (son[x] == -1 || siz[son[x]] < siz[y])
			son[x] = y;
	}
}
void cut(int x, int t)
{
	top[x] = t;
	dfn[x] = ++cnt;
	rnk[dfn[x]] = x;
	if (son[x] == -1)
		return ;
	cut(son[x], t);
	for (int i = head[x]; ~i; i = e[i].nxt)
	{
		int y = e[i].to;
		if (y != fa[x] && y != son[x])
			cut(y, y);
	}
}
int getLca(int x, int y)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] > dep[top[y]])
			x = fa[top[x]];
		else
			y = fa[top[y]];
	}
	return (dep[x] < dep[y]) ? x : y;
}
void dfs(int x)
{
	int t1 = bu1[w[x] + dep[x]], t2 = bu2[w[x] - dep[x] + MAXN];
	for (int i = head[x]; ~i; i = e[i].nxt)
	{
		int y = e[i].to;
		if (y != fa[x])
			dfs(y);
	}
	bu1[dep[x]] += st[x];
	for (int i = head1[x]; ~i; i = e1[i].nxt)
	{
		int y = e1[i].to;
		bu2[dist[y] - dep[t[y]] + MAXN]++;
	}
	ans[x] += bu1[w[x] + dep[x]] - t1 + bu2[w[x] - dep[x] + MAXN] - t2;
	for (int i = head2[x]; ~i; i = e2[i].nxt)
	{
		int y = e2[i].to;
		bu1[dep[s[y]]]--;
		bu2[dist[y] - dep[t[y]] + MAXN]--;
	}
}
int main()
{
	input();
	setup(1, 0);
	cut(1, 1);
	for (int i = 1; i <= m; i++)
	{
		int lca = getLca(s[i], t[i]);
		dist[i] = dep[s[i]] + dep[t[i]] - 2 * dep[lca];
		st[s[i]]++;
		add1(t[i], i);
		add2(lca, i);
		if (dep[lca] + w[lca] == dep[s[i]])
			ans[lca]--;
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
