#include <bits/stdc++.h>

using namespace std;

int n;

int t, a[50010], c[50010];

char s[10];

int lowbit(int x)
{

	return x & (-x);
}

void add(int x, int d)
{

	while (x <= n)
	{

		c[x] += d;

		x += lowbit(x);
	}
}

void del(int x, int d)
{

	while (x <= n)
	{

		c[x] -= d;

		x -= lowbit(x);
	}
}

int sum(int x)
{

	int v = 0;

	while (x > 0)
	{

		v += c[x];

		x -= lowbit(x);
	}

	return v;
}

int main()
{

	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{

		printf("Case %d:\n", i);

		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{

			scanf("%d", &a[i]);
		}

		memset(c, 0, sizeof(c));

		for (int i = 1; i <= n; i++)

			add(i, a[i]);

		scanf("%s", s);

		while (true)
		{

			if (s[0] == 'E')

				break;

			int i, j;

			scanf("%d%d", &i, &j);

			if (s[0] == 'A')
			{

				add(i, j);
			}

			else if (s[0] == 'S')
			{

				add(i, -j);
			}

			else
			{

				printf("%d\n", sum(j) - sum(i - 1));
			}

			scanf("%s", s);
		}
	}

	return 0;
}
