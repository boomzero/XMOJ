#include <bits/stdc++.h>
const int N = 800010;
using namespace std;
int n, m, f[N], ans[N], tot;
int deep[N], r2, q[N];
struct node
{
	int l, r, id;
} s[N];
bool cmp(node a, node b)
{
	return a.l < b.l;
}
struct node2
{
	int v, next;
} e[N];
void process(int t1, int t2)
{
	e[++tot].v = t2;
	e[tot].next = f[t1];
	f[t1] = tot;
}
void dfs(int k, int fa, int T)
{
	q[++r2] = k;
	deep[k] = deep[fa] + 1;
	int now = T;
	if (s[k].id != 0)
	{
		while (s[q[now]].r >= s[k].l + m && now <= r2)
			now++;
		ans[s[k].id] = deep[k] - deep[q[now - 1]] + 1;
	}
	for (int i = f[k]; i; i = e[i].next)
	{
		dfs(e[i].v, k, now);
	}
	r2--;
}
int main()
{
	//	freopen("test.in","r",stdin);
	//	freopen("test.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &s[i].l, &s[i].r);
		s[i].id = i;
		if (s[i].l > s[i].r)
			s[i].r += m;
		s[i + n].l = s[i].l + m, s[i + n].r = s[i].r + m;
	}
	sort(s + 1, s + n * 2 + 1, cmp);
	int j = 1;
	for (int i = 1; i < n + n; i++)
	{
		for (; s[j].l <= s[i].r && j <= n + n; j++)
			;
		process(j - 1, i);
	}
	dfs(n + n, 0, 1);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}
