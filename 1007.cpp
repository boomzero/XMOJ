#include <bits/stdc++.h>
using namespace std;
long long n, a[400][400], f[400][400], maxn;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}
	f[1][1] = a[1][1];
	for (int i = 1; i <= n; i++)
	{
		f[i][1] = f[i - 1][1] + a[i][1];
		f[i][i] = f[i - 1][i - 1] + a[i][i];
		for (int j = 2; j <= i - 1; j++)
		{
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		maxn = max(f[n][i], maxn);
	}
	cout << maxn;
	return 0;
}
