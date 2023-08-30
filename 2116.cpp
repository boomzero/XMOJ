#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 2010
#define MAXM 10010
int n, m;
int k[MAXN];
struct Edge
{
	int v, nxt;
} e[MAXM << 1];
int head[MAXN], rhead[MAXN], cnt = 1;
void add(int u, int v)
{
	e[cnt].v = v;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
	e[cnt].v = u;
	e[cnt].nxt = rhead[v];
	rhead[v] = cnt++;
}
int vis[MAXN], rvis[MAXN];
int num[MAXN][MAXN], ccnt[MAXN];
int dfs(int cur)
{
	if (vis[cur])
		return k[cur];
	vis[cur] = 1;
	for (int i = head[cur]; i; i = e[i].nxt)
	{
		int res = dfs(e[i].v);
		if (k[cur] > res - 1)
			k[cur] = res - 1;
	}
	num[k[cur]][ccnt[k[cur]]++] = cur;
	return k[cur];
}
void rdfs(int cur)
{
	rvis[cur] = 1;
	for (int i = rhead[cur]; i; i = e[i].nxt)
		if (!rvis[e[i].v])
			rdfs(e[i].v);
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
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(k[i]);
	while (m--)
	{
		int u, v;
		read(u), read(v);
		add(u, v);
	}
	for (int i = 1; i <= n; i++)
		dfs(i);
	for (int i = 1; i <= n; i++)
	{
		memset(rvis, 0, sizeof(rvis));
		rdfs(i);
		int p = n;
		for (int j = n; j >= 1; j--)
		{
			if (p > j)
				break;
			for (int t = 0; t < ccnt[j]; t++)
				if (!rvis[num[j][t]])
					p--;
		}
		printf("%d ", p);
	}
	printf("\n");
	return 0;
}
