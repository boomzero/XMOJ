#include <bits/stdc++.h>
using namespace std;
int n, k, x[110], ans;
int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (x[i] < k - x[i])
			ans += x[i] * 2;
		else
			ans += (k - x[i]) * 2;
	}
	printf("%d", ans);
	return 0;
}
