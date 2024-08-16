#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010], mn = 1000, x;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		a[x] += 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (mn > a[i])
		{
			mn = a[i];
		}
	}
	cout << mn;
	return 0;
}
