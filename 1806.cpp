#include <bits/stdc++.h>

using namespace std;

int n, a[2010], t[2010], lasthight = 30000, ans, cnt;

bool judge()
{

	for (int i = 0; i < n; i++)
	{

		if (t[i] == false)
			return true;
	}

	return false;
}

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> a[i];

		t[i] = false;
	}

	while (judge() == true)
	{

		ans++;

		lasthight = 30000;

		for (int i = 0; i < n; i++)
		{

			if (t[i] == false && a[i] <= lasthight)
			{

				lasthight = a[i];

				t[i] = true;
			}
		}
	}

	cout << ans;

	return 0;
}
