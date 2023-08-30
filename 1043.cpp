#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[110][110];
int main()
{
	freopen("mine.in", "r", stdin);
	freopen("mine.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int ans = 0;
			if (a[i][j] == '*')
				cout << "*";
			else
			{
				if (j != 0 && a[i][j - 1] == '*')
				{
					ans++;
				}
				if (j != 0 && i != n - 1 && a[i + 1][j - 1] == '*')
				{
					ans++;
				}
				if (i != n - 1 && a[i + 1][j] == '*')
				{
					ans++;
				}
				if (j != m - 1 && i != n - 1 && a[i + 1][j + 1] == '*')
				{
					ans++;
				}
				if (j != m - 1 && a[i][j + 1] == '*')
				{
					ans++;
				}
				if (j != m - 1 && i != 0 && a[i - 1][j + 1] == '*')
				{
					ans++;
				}
				if (i != 0 && a[i - 1][j] == '*')
				{
					ans++;
				}
				if (i != 0 && j != 0 && a[i - 1][j - 1] == '*')
				{
					ans++;
				}
				cout << ans;
			}
		}
		cout << endl;
	}
	return 0;
}
