#include <bits/stdc++.h>
using namespace std;
long long n, k, a[100010], l, r;
long long ans;
int main()
{
	freopen("enough.in", "r", stdin);
	freopen("enough.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	long long r = 1, ret = a[1];
	for (int i = 1; i <= n; i++)
	{
		while (ret < k && r <= n)
		{
			r++, ret += a[r];
		}
		if (ret >= k)
			ans += n - r + 1;
		ret -= a[i];
	}
	printf("%lld", ans);
	return 0;
}
