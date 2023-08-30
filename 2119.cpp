#include <bits/stdc++.h>

using namespace std;

int st[220], top = 0, size = 0, head[220], du[220];

int n, m, c[220], U[220], can[220], cnt = 0;

struct edge
{

	int v, w, nxt;

} e[10010];

inline int read()
{

	int x = 0, f = 1;

	char c = getchar();

	while (c < '0' || c > '9')
	{

		if (c == '-')
			f = -1;

		c = getchar();
	}

	while (c >= '0' && c <= '9')
	{

		x = (x << 3) + (x << 1) + c - '0';

		c = getchar();
	}

	return x * f;
}

inline void add(int u, int v, int w)
{

	e[++size].v = v;

	e[size].w = w;

	e[size].nxt = head[u];

	head[u] = size;
}

inline void sortt_()
{

	int t = 0;

	while (t < top)
	{

		int u = st[++t];

		if (c[u] <= 0)
		{

			for (int i = head[u]; ~i; i = e[i].nxt)
			{

				int v = e[i].v;

				--du[v];

				if (!du[v])
					st[++top] = v;
			}

			continue;
		}

		for (int i = head[u]; ~i; i = e[i].nxt)
		{

			int v = e[i].v, w = e[i].w;

			c[v] += w * c[u];

			--du[v];

			if (!du[v])
				st[++top] = v;
		}
	}

	int pd = 0;

	for (int i = 1; i <= n; ++i)
	{

		if (head[i] == -1)
		{

			if (c[i] != 0)
			{

				pd = 1;

				break;
			}
		}
	}

	if (!pd)
		printf("NULL");

	else
	{

		for (int i = 1; i <= n; ++i)
		{

			if (head[i] == -1 && c[i] > 0)
			{

				printf("%d %d\n", i, c[i]);
			}
		}
	}
}

int main()
{

	n = read();
	m = read();

	memset(head, -1, sizeof(head));

	memset(du, 0, sizeof(du));

	for (int i = 1; i <= n; ++i)
	{

		c[i] = read();
		U[i] = read();
	}

	int x, y, z;

	for (int i = 1; i <= m; ++i)
	{

		x = read();
		y = read();
		z = read();

		add(x, y, z);

		++du[y];
	}

	for (int i = 1; i <= n; ++i)
	{

		if (!du[i])
			st[++top] = i;

		else
			c[i] -= U[i];
	}

	sortt_();

	return 0;
}
