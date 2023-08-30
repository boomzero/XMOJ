#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define min(a, b) a < b ? a : b
using namespace std;
int n, m, ans = 0x7f7f7f7f;
int map[21][21], f[1 << 20][21];
int main()
{
	scanf("%d", &n);
	m = (1 << n) - 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	memset(f, 0x7f, sizeof(f));
	f[1][1] = 0;
	for (int i = 3, k = 2, p = 4; i <= m; i += 2)
	{
		if (i > p)
			p = p << 1, k++;
		for (int j = 2; j <= k; j++)
		{
			if ((i >> j - 1) & 1)
			{
				int s = i ^ (1 << j - 1);
				for (int l = 1; l < j; l++)
				{
					f[i][j] = min(f[i][j], f[s][l] + map[l][j]);
				}
				for (int l = j + 1; l <= k; l++)
				{
					f[i][j] = min(f[i][j], f[s][l] + map[l][j]);
				}
			}
		}
	}
	for (int i = 2; i <= n; i++)
		ans = min(ans, f[m][i] + map[i][1]);
	cout << ans;
}
