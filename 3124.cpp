#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1001][1001], b, c, d, e, f, dp[100001];
int main()
{
	freopen("souvenir.in", "r", stdin);
	freopen("souvenir.out", "w", stdout);
	cin >> b >> c >> d;
	e = d;
	if (b == 1)
	{
		cout << d;
		return 0;
	}
	for (int i = 1; i <= b; i++)
	{
		if (i != 2)
			e += dp[e];
		memset(dp, 0, sizeof(dp));
		for (register int j = 1; j <= c; j++)
			scanf("%d", &a[i][j]);
		for (register int j = 1; j <= c; j++)
			for (register int k = a[i - 1][j]; k <= e; k++)
				if (a[i][j] - a[i - 1][j])
					dp[k] = max(dp[k], dp[k - a[i - 1][j]] + (a[i][j] - a[i - 1][j]));
	}
	cout << e + dp[e];
}
