#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = 2e6 + 5;

struct E
{

	int to, next;

} e[M];

int n, u, v, sz, rt, h[N], num, dfn[N], low[N];

char c;

bool cutt[N];

void add(int u, int v)
{

	e[++sz].to = v;

	e[sz].next = h[u];

	h[u] = sz;
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

				if (u != rt || cnt > 1)

					cutt[u] = true;
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

		memset(cutt, false, sizeof(cutt));

		sz = 0, num = 0;

		while (~scanf("%d", &u) && u)
		{

			int T;

			scanf("%d", &T);

			for (int i = 0; i < T; i++)
			{

				scanf("%d", &v);

				add(u, v);

				add(v, u);
			}
		}

		for (rt = 1; rt <= n; rt++)
		{

			if (!dfn[rt])

				tarjan(rt);
		}

		int ans = 0;

		for (int i = 1; i <= n; i++)

			if (cutt[i])

				ans++;

		printf("%d\n", ans);
	}

	return 0;
}
