#include <bits/stdc++.h>

using namespace std;

int n, s[3010], ans;

int main()

{

	freopen("c.in", "r", stdin);

	freopen("c.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> s[i];
	}

	for (int i = 0; i < n; i++)
	{

		ans += s[i] - 1;
	}

	cout << ans;

	return 0;
}
