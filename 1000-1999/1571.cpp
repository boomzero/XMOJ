#include <iostream>
#include <cstdio>
using namespace std;
struct Tree
{
	int to, next;
} a[220];
int n, m, x, y, z, t, p[200], b[220][220], f[220][220], head[220];
inline void dp(int d)
{
	p[d] = 1;
	for (int i = head[d]; i; i = a[i].next)
	{
		if (p[a[i].to] == 1)
			continue;
		dp(a[i].to);
		for (int j = m; j > 0; j--)
			for (int k = j - 1; k >= 0; k--)
				f[d][j] = max(f[d][j], f[a[i].to][k] + f[d][j - k - 1] + b[d][a[i].to]);
	}
}
inline void add(int x, int y)
{
	a[++t].to = y;
	a[t].next = head[x];
	head[x] = t;
}
int main()
{
	cin.tie(0), cout.tie(0);
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		b[x][y] = b[y][x] = z;
		add(x, y);
		add(y, x);
	}
	dp(1);
	cout << f[1][m];
	return 0;
}
