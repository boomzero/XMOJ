#include <bits/stdc++.h>
using namespace std;
int n, v[30], c[30], ans;
int main()
{
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i] - c[i] >= 0)
			ans += v[i] - c[i];
	}
	printf("%d", max(0, ans));
	return 0;
}
