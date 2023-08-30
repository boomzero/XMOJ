#include <bits/stdc++.h>
using namespace std;
const int inn = 100001;
struct node
{
	int x, y, next;
} a[inn];
int n, m, low[inn], dfn[inn], lis[inn], tt[inn], belong[inn], out[inn], w[inn];
int ans, naa, tg;
bool b[inn];
void tarjan(int q)
{
	int h;
	low[q] = dfn[q] = ++naa;
	tt[++ans] = q;
	b[q] = true;
	for (int t = lis[q]; t; t = a[t].next)
	{
		h = a[t].y;
		if (!dfn[h])
		{
			tarjan(h);
			low[q] = min(low[q], low[h]);
		}
		else if (b[h])
			low[q] = min(dfn[h], low[q]);
	}
	if (dfn[q] == low[q])
	{
		tg++;
		do
		{
			w[tg]++;
			h = tt[ans];
			ans--;
			b[h] = false;
			belong[h] = tg;
		} while (q != h);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	int xx, yy;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &xx, &yy);
		a[i].x = xx;
		a[i].y = yy;
		a[i].next = lis[xx];
		lis[xx] = i;
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= m; i++)
		if (belong[a[i].x] != belong[a[i].y])
			out[belong[a[i].x]]++;
	int ttt = 0, num = 0;
	for (int i = 1; i <= tg; i++)
	{
		if (!out[i])
		{
			ttt = i;
			num++;
		}
	}
	if (num == 1)
	{
		printf("%d", w[ttt]);
		return 0;
	}
	printf("0");
	return 0;
}
