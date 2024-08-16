#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, l, r, k, mid, num, a[100][100];
char x;
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			cin>>x;
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + x - 48;
			r += x - 48;
		}
	l = 1;
	while (l < r)
	{
		num = 0;
		mid = (l + r + 1) >> 1;
		for (int c1 = 1; c1 <= m - 3 && num < 4; ++c1)
			for (int c2 = c1 + 1; c2 <= m - 2 && num < 4; ++c2)
				for (int c3 = c2 + 1; c3 <= m - 1 && num < 4; ++c3)
		{
			k = 1;
			num = 0;
			for (int i = 1; i <= n; ++i)
				if (a[i][c1] - a[k - 1][c1] >= mid
					&& a[i][c2] - a[k - 1][c2] - a[i][c1] + a[k - 1][c1] >= mid
					&& a[i][c3] - a[k - 1][c3] - a[i][c2] + a[k - 1][c2] >= mid
					&& a[i][m] - a[k - 1][m] - a[i][c3] + a[k - 1][c3] >= mid)
			{
				k = i + 1;
				num++;
			}
		}
		if (num >= 4) l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
}
