#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, n;
	int dp[10210] = {0};
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		int v, t, num;
		cin >> num >> v >> t;
		for (int shit = 1; shit <= num; shit++)
		{
			for (int j = m; j >= v; j--)
				dp[j] = max(dp[j], dp[j - v] + t);
		}
	}
	cout << dp[m];
	return 0;
}
