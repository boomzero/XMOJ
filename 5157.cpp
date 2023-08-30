#include <bits/stdc++.h>

using namespace std;

const int Max = 1010;

int n, m = 1, size, tot1, tot2, p1[Max], p2[Max];

int first[Max], f[Max], num[Max], vis[Max];

struct shu
{
	int to, next, len;
} edge[Max * Max];

inline int get_int()

{

	int x = 0, f = 1;

	char c;

	for (c = getchar(); (!isdigit(c)) && (c != '-'); c = getchar())
		;

	if (c == '-')
		f = -1, c = getchar();

	for (; isdigit(c); c = getchar())
		x = (x << 3) + (x << 1) + c - '0';

	return x * f;
}

inline void build(int x, int y)

{

	edge[++size].next = first[x], first[x] = size, edge[size].to = y;

	edge[++size].next = first[y], first[y] = size, edge[size].to = x;
}

inline void pre()

{

	f[n] = num[n];

	for (int i = n - 1; i >= 1; i--)
		f[i] = min(f[i + 1], num[i]);

	for (int i = 1; i <= n; i++)

		for (int j = i + 1; j <= n; j++)

			if (f[j] < num[i] && num[i] < num[j])
				build(i, j);
}

inline bool dfs(int p, int color)

{

	vis[p] = color;

	for (int u = first[p]; u; u = edge[u].next)

	{

		int to = edge[u].to;

		if (!vis[to])
			dfs(to, 3 - color);

		else if (color == vis[to])
			return 0;
	}

	return 1;
}

int main()

{

	n = get_int();

	for (int i = 1; i <= n; i++)
		num[i] = get_int();

	pre();

	for (int i = 1; i <= n; i++)
		if (!vis[i] && !dfs(i, 1))
		{
			puts("0");
			return 0;
		}

	for (int i = 1; i <= n; i++)

	{

		if (vis[i] == 1)
			p1[++tot1] = num[i], printf("a ");

		else
			p2[++tot2] = num[i], printf("c ");

		while (m == p1[tot1] || m == p2[tot2])

		{

			if (m == p1[tot1])
				tot1--, printf("b ");

			else
				tot2--, printf("d ");

			m++;
		}
	}

	return 0;
}
