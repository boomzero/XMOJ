#include <cstdio>
#include <cstring>
#define max(a, b) (a > b ? a : b)
int n, m, c, i, j, k, x, y, ans;
int a[10005], b[10005], f[10005], q[10005];
int main()
{
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}
	f[1] = a[1];
	for (k = 1; k <= c; k++)
	{
		x = 1, y = 0;
		memset(q, 0, sizeof(q));
		for (i = j = n; i > 0; i--)
		{
			while (j > 0 && b[j] + m >= b[i])
			{
				q[++y] = j--;
				while (q[x] >= i)
					x++;
				while (x < y && f[q[y]] >= f[q[y - 1]])
				{
					q[y - 1] = q[y], y--;
				}
			}
			while (q[x] >= i)
				x++;
			if (f[q[x]])
				f[i] = f[q[x]] + a[i];
		}
	}
	for (i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	printf("%d", ans);
	return 0;
}
