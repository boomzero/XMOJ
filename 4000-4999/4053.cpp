#include <bits/stdc++.h>
using namespace std;
int n, a[20][20], ans;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string x;
		cin >> x;
		int len = x.size();
		for (int j = 0; j < len; j++)
		{
			a[i][j] = x[j] - '0';
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (a[i][j])
			{
				ans++;
				for (int k = 0; k <= i; k++)
				{
					for (int l = 0; l <= j; l++)
					{
						a[k][l] = !a[k][l];
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
