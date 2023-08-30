#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
bool visit[400010] = {false}, pop[400010] = {false}; // pop: whether or not to be deleted
int n, m, k, t, num = 0, ans[200010] = {0}, fa[400010] = {0};
int cnt = 0, nxt[400010] = {0}, point[400010] = {0}, edge[400010] = {0};
int del[400010] = {0}; // points that need to be deleted
void add(int u, int v)
{
	cnt++;
	nxt[cnt] = point[u];
	point[u] = cnt;
	edge[cnt] = v;
}
int find(int x)
{
	if (x == fa[x])
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int x)
{
	int f1 = find(x);
	int y = point[x];
	while (y != 0)
	{
		int f2 = find(edge[y]);
		if (visit[edge[y]] == true)
			if (f1 != f2)
			{
				fa[f2] = f1;
				num--;
			}
		y = nxt[y];
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
int main()
{
	IO::read(n), IO::read(m);
	for (int i = 0; i <= n - 1; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		IO::read(x), IO::read(y);
		add(x, y);
		add(y, x);
	}
	IO::read(t);
	for (int i = 1; i <= t; i++)
	{
		IO::read(k);
		del[i] = k;
		pop[k] = true;
	}
	for (int i = 0; i <= n - 1; i++)
	{
		if (pop[i] == false)
		{
			num++;
			merge(i);
			visit[i] = true;
		}
	}
	ans[t + 1] = num;
	for (int i = t; i >= 1; i--)
	{
		num++;
		merge(del[i]);
		visit[del[i]] = true;
		ans[i] = num;
	}
	for (int i = 1; i <= t + 1; i++)
		IO::write(ans[i]), printf("\n");
	return 0;
}
