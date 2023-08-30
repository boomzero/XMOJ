#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = 2e6 + 5;
struct E
{
	int to, next;
} e[M];
int n, u, v, len, root, h[N], num, dfn[N], low[N];
char c;
bool cut[N];
void add(int u, int v)
{
	e[++len].to = v;
	e[len].next = h[u];
	h[u] = len;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++num;
	int cnt = 0;
	for (int j = h[u]; j; j = e[j].next)
	{
		int v = e[j].to;
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u])
			{
				cnt++;
				if (u != root || cnt > 1)
					cut[u] = true;
			}
		}
		else
			low[u] = min(low[u], dfn[v]);
	}
}
int main()
{
	while (~scanf("%d", &n) && n)
	{
		memset(h, 0, sizeof(h));
		memset(dfn, 0, sizeof(dfn));
		memset(cut, false, sizeof(cut));
		len = 0, num = 0;
		while (~scanf("%d", &u) && u)
		{
			while (~scanf("%c", &c) && c != '\n')
			{
				scanf("%d", &v);
				add(u, v);
				add(v, u);
			}
		}
		for (root = 1; root <= n; root++)
		{
			if (!dfn[root])
				tarjan(root);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (cut[i])
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
