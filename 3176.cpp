#include <bits/stdc++.h>

using namespace std;

int n, m, k, house[110], ans = 10000;

int main()
{

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{

		cin >> house[i];
	}

	for (int i = 0; i < n; i++)
	{

		if (house[i] != 0 && house[i] <= k)
		{

			ans = min(ans, abs(m - 1 - i) * 10);
		}
	}

	cout << ans;

	return 0;
}
