#include <bits/stdc++.h>

using namespace std;

int m, n, mx, mn = 1e9, mxdir, mndir = 1e9;

int dir[10] = {10, 5, 9, 8, 3, 2, 7, 6, 1, 4};

int main()
{

	freopen("order.in", "r", stdin);

	freopen("order.out", "w", stdout);

	scanf("%d%d", &m, &n);

	for (int i = m; i <= n; i++)
	{

		int num;

		if (i < 10)
		{

			num = dir[i];

			if (mxdir < num)
			{

				mx = i, mxdir = num;
			}

			if (mndir > num)
			{

				mn = i, mndir = num;
			}
		}

		else if (i < 100)
		{

			num = dir[i / 10] * 10 + dir[i % 10];

			if (mxdir < num)
			{

				mx = i, mxdir = num;
			}

			if (mndir > num)
			{

				mn = i, mndir = num;
			}
		}

		else
		{

			num = dir[i / 100] * 100 + dir[i / 10 % 10] * 10 + dir[i % 10];

			if (mxdir < num)
			{

				mx = i, mxdir = num;
			}

			if (mndir > num)
			{

				mn = i, mndir = num;
			}
		}
	}

	printf("%d %d", mn, mx);

	return 0;
}
