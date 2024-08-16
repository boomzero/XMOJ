#include <bits/stdc++.h>
using namespace std;
int n, ans, oushu, jishu;
long long a[10010];
int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		while (a[i] != 0 && a[i] % 2 == 0)
		{
			a[i] /= 2;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
