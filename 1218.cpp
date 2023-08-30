#include <bits/stdc++.h>
using namespace std;
const int Max = 5000;
const int inf = 1e9;
int n, m, ans = 1e9, tot;
int dis[20][20], f[20][Max];
int p[Max], num[Max], pos[Max], sum[Max], condition[Max];
inline int get_int()
{
	int x = 0, f = 1;
	char c;
	for (c = getchar(); (!isdigit(c)) && (c != '-'); c = getchar())
		;
	if (c == '-')
	{
		f = -1;
		c = getchar();
	}
	for (; isdigit(c); c = getchar())
		x = (x << 3) + (x << 1) + c - '0';
	return x * f;
}
inline int mn(int x, int y) { return x < y ? x : y; }
int main()
{
	n = get_int(), m = get_int();
	memset(f, 0x3f, sizeof(f));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dis[i][j] = 10000000;
	for (int i = 1; i <= m; i++)
	{
		int x = get_int() - 1, y = get_int() - 1, z = get_int();
		dis[x][y] = dis[y][x] = mn(z, dis[x][y]);
	}
	for (int i = 0; i < n; i++)
		pos[1 << i] = i, f[0][1 << i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (1 << n); j++)
		{
			tot = 0;
			for (int to = 0; to < n; to++)
			{
				if ((1 << to) & j)
					continue;
				p[tot] = 1 << to;
				num[tot] = 10000000;
				for (int k = j; k; k -= k & (-k))
				{
					int from = pos[k & (-k)];
					num[tot] = mn(num[tot], dis[from][to] * (i + 1));
				}
				tot++;
			}
			for (int k = 1; k < (1 << tot); k++)
			{
				condition[k] = condition[k - (k & (-k))] | p[pos[k & (-k)]];
				sum[k] = sum[k - (k & (-k))] + num[pos[k & (-k)]];
				f[i + 1][j | condition[k]] = mn(f[i + 1][j | condition[k]], f[i][j] + sum[k]);
			}
		}
	for (int i = 0; i <= n; i++)
		ans = mn(ans, f[i][(1 << n) - 1]);
	cout << ans << "\n";
	return 0;
}
