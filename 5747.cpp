#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll longlong
using namespace std;
struct Road
{
	int x, y;
} a[2001];
struct A
{
	int from, to;
	double val;
} e[1000001];
int map[1001][1001];
double calc(int x1, int x2)
{
	double ans = sqrt((double)(a[x1].x - a[x2].x) * (a[x1].x - a[x2].x) + (double)(a[x1].y - a[x2].y) * (a[x1].y - a[x2].y));
	return ans;
}
int fa[1001];
bool cmp(A a, A b)
{
	return a.val < b.val;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int n, m, tot = 0;
double ans = 0;
int cnt = 0;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, xx, yy; i <= n; i++)
	{
		scanf("%d%d", &xx, &yy);
		a[i].x = xx;
		a[i].y = yy;
	}
	for (int i = 1, x, y; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		e[++tot].from = x;
		e[tot].to = y;
		e[tot].val = 0;
		map[x][y] = 1;
	}
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (i == j || map[i][j] == 1)
				continue;
			e[++tot].from = i;
			e[tot].to = j;
			e[tot].val = calc(i, j);
		}
	sort(e + 1, e + 1 + tot, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= tot && cnt < n - 1; i++)
	{
		int u = find(e[i].from), v = find(e[i].to);
		if (u == v)
			continue;
		ans += e[i].val, cnt++, fa[u] = v;
	}
	printf("%.2f", ans);
	return 0;
}
