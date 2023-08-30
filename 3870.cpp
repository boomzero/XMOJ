#include <bits/stdc++.h>

using namespace std;

int n, a[30];

int main()
{

	freopen("power.in", "r", stdin);

	freopen("power.out", "w", stdout);

	cin >> n;

	if (n % 2 == 1)
	{

		cout << -1;

		return 0;
	}

	for (int i = 30; i > 0; i--)
	{

		if (n & (1 << i))
		{

			cout << (1 << i) << " ";
		}
	}

	return 0;
}
