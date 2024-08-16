#include <cstdio>
#define ms 31000
int fa[ms], dis[ms], n, m, tot[ms];
int gf(int id)
{
	if (fa[id] == id)
		return fa[id];
	int temp = fa[id];
	fa[id] = gf(fa[id]);
	dis[id] += dis[temp];
	return fa[id];
}
void merge(int x, int y)
{
	int f1 = gf(x), f2 = gf(y);
	if (f1 != f2)
	{
		fa[f2] = f1;
		dis[f2] = tot[f1];
		tot[f1] += tot[f2];
	}
}
int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= ms - 1; i++)
	{
		fa[i] = i;
		tot[i] = 1;
	}
	for (int i = 1; i <= p; i++)
	{
		int x, y;
		char t[10];
		scanf("%s", t);
		if (t[0] == 'M')
		{
			scanf("%d%d", &x, &y);
			merge(x, y);
		}
		if (t[0] == 'C')
		{
			scanf("%d", &x);
			printf("%d\n", tot[gf(x)] - dis[x] - 1);
		}
	}
	getchar();
	getchar();
}
