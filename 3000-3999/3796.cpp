#include <bits/stdc++.h>
using namespace std;
int anc[300010][26], dep[300010], n, q, m[300010], f[300010], c[300010], tot, val[300010], de[300010];
vector<int> g[300010];
void dfs(int x, int fa)
{
	f[x] = fa;
	dep[x] = dep[fa] + 1;
	anc[x][0] = fa;
	for (int i = 1; i < 26; i++)
		anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for (int i = 0; i < g[x].size(); i++)
		if (g[x][i] != fa)
			dfs(g[x][i], x);
}
int lca(int x, int y)
{
	if (dep[x] < dep[y])
		swap(x, y);
	for (int i = 25; i >= 0; i--)
		if (dep[anc[x][i]] >= dep[y])
			x = anc[x][i];
	if (x == y)
		return y;
	for (int i = 25; i >= 0; i--)
		if (anc[x][i] != anc[y][i])
		{
			x = anc[x][i];
			y = anc[y][i];
		}
	return anc[x][0];
}
void cf(int x, int y)
{
	c[x]++;
	c[y]++;
	c[lca(x, y)]--;
	c[f[lca(x, y)]]--;
}
int pup(int x)
{
	int t = c[x];
	for (int i = 0; i < g[x].size(); i++)
		if (g[x][i] != f[x])
			t += pup(g[x][i]);
	return val[x] = t;
}
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
inline void write(int x)
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
int main()
{
	freopen("visit.in", "r", stdin);
	freopen("visit.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++)
		read(m[i]);
	for (int i = 1, x, y; i < n; i++)
	{
		read(x), read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i < n; i++)
	{
		cf(m[i], m[i + 1]);
		de[m[i + 1]]++;
	}
	pup(1); // 有的地方差分时多经过一次
	for (int i = 1; i <= n; i++)
		write(val[i] - de[i]), printf("\n");
}
