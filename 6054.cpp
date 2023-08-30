#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int n, m;

int nxt[maxn << 1], to[maxn << 1], head[maxn], cnt;

void add(int u, int v)
{

	to[++cnt] = v;

	nxt[cnt] = head[u];

	head[u] = cnt;
}

int f[maxn], s[maxn];

int find(int x)
{

	return x == f[x] ? x : find(f[x]);
}

int ans[maxn], p[maxn];

void dfs(int u, int ss)
{

	for (int i = head[u]; i; i = nxt[i])
	{

		int v = to[i];

		if (ans[v] || ans[u] == v)

			continue;

		ans[v] = u;

		if (v == ss)

			continue;

		dfs(v, ss);
	}
}

namespace IO
{

	template <typename T>
	void read(T &a)
	{

		a = 0;
		int f = 1;
		char ch = getchar();

		while (ch < '0' || ch > '9')
		{
			if (ch == '-')
				f = -1;
			ch = getchar();
		}

		do
		{
			a = a * 10 + ch - '0';
			ch = getchar();
		} while ('0' <= ch && ch <= '9');

		a *= f;
	}

	template <typename T>
	void write(T x)
	{

		if (!x)
			putchar('0');

		char f[200];

		int tmp = x > 0 ? x : -x;

		if (x < 0)
			putchar('-');

		int cnt = 0;

		while (tmp > 0)
		{

			f[cnt++] = tmp % 10 + '0';

			tmp /= 10;
		}

		while (cnt > 0)
			putchar(f[--cnt]);
	}

}

using namespace IO;

int main()
{

	read(n), read(m);

	for (int i = 1; i <= n; i++)

		f[i] = i;

	for (int i = 1; i <= m; i++)
	{

		int u, v;

		read(u), read(v);

		add(u, v);

		add(v, u);

		int fx = find(u), fy = find(v);

		if (fx == fy)

			s[++s[0]] = u;

		f[fx] = fy;
	}

	if (!s)
	{

		printf("NIE\n");

		return 0;
	}

	for (int i = 1; i <= s[0]; i++)

		if (!ans[s[i]])

			dfs(s[i], s[i]);

	for (int i = 1; i <= n; i++)
	{

		if (ans[i] == 0)
		{

			printf("NIE\n");

			return 0;
		}
	}

	printf("TAK\n");

	return 0;
}
