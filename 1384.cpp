#include <bits/stdc++.h>

using namespace std;

int c[5006], a[5006], n;

int lowbit(int i)
{

	return i & (-i);
}

void add(int k, int v)
{

	while (k <= n)

	{

		c[k] = c[k] + v;

		k = k + lowbit(k);
	}
}

int sum(int k)
{

	int res = 0;

	while (k)
	{

		res = res + c[k];

		k = k - lowbit(k);
	}

	return res;
}

int main()
{

	int ans, t;

	cin >> t;

	while (t--)
	{

		cin >> n;

		memset(c, 0, sizeof(c));

		for (int i = 0; i < n; i++)

			scanf("%d", &a[i]);

		int re = 0;

		for (int i = 0; i < n; i++)
		{

			re = re + sum(n - a[i]);

			add(n - a[i], 1);
		}

		int tp = re;

		ans = re;

		for (int i = 0; i < n - 1; i++)
		{

			add(n - a[i], -1);

			tp = tp + sum(n - a[i]) - a[i];

			add(n - a[i], 1);

			ans = min(tp, ans);
		}

		cout << ans << '\n';
	}

	return 0;
}
