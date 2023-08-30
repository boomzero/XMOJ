#include <bits/stdc++.h>

using namespace std;

int n, a[110], ans;

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> a[i];
	}

	sort(a + 0, a + 0 + n);

	for (int i = 0; i < n; i += 2)
	{

		ans += a[i + 1] - a[i];
	}

	cout << ans;
}
