#include <bits/stdc++.h>

using namespace std;

int n, z, w, a[2010], ans;

int main()
{

	ios::sync_with_stdio(false);

	cin.tie(0), cout.tie(0);

	cin >> n >> z >> w;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	if (n == 1)
	{

		cout << abs(a[1] - w);

		return 0;
	}

	ans = max(ans, abs(a[n] - w));

	ans = max(ans, abs(a[n] - a[n - 1]));

	cout << ans;

	return 0;
}
