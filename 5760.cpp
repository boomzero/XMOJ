#include <cstdio>

#include <cstring>

#include <stack>

#define MAXN 10005

using namespace std;

struct Edge
{

	int v, next;

	Edge(){};

	Edge(int _v, int _next)
	{

		v = _v, next = _next;
	}

} edge[MAXN * 5];

int EdgeCount, head[MAXN];

int n, m, cnt, color;

int dfn[MAXN], low[MAXN], num[MAXN], sum[MAXN];

bool vis[MAXN];

stack<int> s;

void addEdge(int u, int v)

{

	edge[++EdgeCount] = Edge(v, head[u]);

	head[u] = EdgeCount;
}

int read()

{

	int sum = 0;

	char c = getchar();

	while (c < '0' || c > '9')
		c = getchar();

	while (c >= '0' && c <= '9')
	{

		sum = sum * 10 + c - '0';

		c = getchar();
	}

	return sum;
}

void init()

{

	memset(head, 0, sizeof(head));

	memset(dfn, 0, sizeof(dfn));

	memset(low, 0, sizeof(low));

	memset(num, 0, sizeof(num));

	memset(sum, 0, sizeof(sum));

	memset(vis, false, sizeof(vis));

	EdgeCount = cnt = color = 0;
}

void tarjan(int u)

{

	dfn[u] = low[u] = ++cnt;

	vis[u] = true;

	s.push(u);

	for (int i = head[u]; i; i = edge[i].next)
	{

		int v = edge[i].v;

		if (!vis[v])
		{

			tarjan(v);

			low[u] = min(low[u], low[v]);
		}

		else if (vis[u])

			low[u] = min(low[u], dfn[v]);
	}

	if (dfn[u] == low[u])
	{

		color++;

		while (1)
		{

			int tmp = s.top();
			s.pop();

			vis[tmp] = false;

			num[tmp] = color;

			if (tmp == u)
				break;
		}
	}
}

int main()

{

	while (~scanf("%d%d", &n, &m))
	{

		init();

		for (int i = 1; i <= m; i++)
		{

			int u = read(), v = read();

			addEdge(u, v);
		}

		for (int i = 1; i <= n; i++)

			if (!dfn[i])

				tarjan(i);

		int ans = 0;

		for (int i = 1; i <= n; i++)

			sum[num[i]]++;

		for (int i = 1; i <= color; i++)

			if (sum[i] > 1)
				ans++;

		printf("%d\n", ans);
	}
}
