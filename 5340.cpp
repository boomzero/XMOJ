#include <bits/stdc++.h>

using namespace std;

int a, b, c, x, ans;

int main()
{

	freopen("money.in", "r", stdin);

	freopen("money.out", "w", stdout);

	cin >> a >> b >> c >> x;

	for (int i = 0; i <= a; i++)
	{

		for (int j = 0; j <= b; j++)
		{

			for (int z = 0; z <= c; z++)
			{

				if (z * 50 + j * 100 + i * 500 == x)
					ans++;
			}
		}
	}

	cout << ans;

	return 0;
}
