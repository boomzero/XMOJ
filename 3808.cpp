#include <bits/stdc++.h>

using namespace std;

#define int long long

#define N 210000

int n, l, r, len;

char a[N], ans[N];

signed main()
{

	freopen("order.in", "r", stdin);

	freopen("order.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	l = 1, r = n;

	while (l <= r)
	{

		if (a[l] < a[r])
		{

			ans[++len] = a[l];

			l += 1;
		}

		else if (a[r] < a[l])
		{

			ans[++len] = a[r];

			r -= 1;
		}

		else
		{

			bool flag = true;

			for (int i = 1; l + i <= r - i; ++i)
			{

				if (a[l + i] != a[r - i])
				{

					if (a[l + i] < a[r - i])
					{

						ans[++len] = a[l];

						l += 1;
					}

					else
					{

						ans[++len] = a[r];

						r -= 1;
					}

					flag = false;

					break;
				}
			}

			if (flag)
			{

				ans[++len] = a[l];

				l += 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{

		cout << ans[i];

		if (i % 80 == 0)
			cout << endl;
	}
}
