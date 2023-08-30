#include <cstdio>
typedef unsigned long long ull;
ull n, m, i, jj, j2, k, max, nans;
ull ans[200010], a[200010], hash[1000007];
ull b[1000007], power[200010], ha1[200010], ha2[200010];
inline ull ha(ull x)
{
	ull y = x % 1000007;
	if (b[y] == m && hash[y] != x)
	{
		y++;
		if (y == n / m)
			y = 0;
	}
	return y;
}
int main()
{
	scanf("%lld", &n);
	power[0] = 1;
	for (m = 1; m <= n; m++)
	{
		scanf("%lld", &a[m]);
		power[m] = power[m - 1] * 19260817, ha1[m] = ha1[m - 1] * 19260817 + a[m];
	}
	for (m = n; m; m--)
		ha2[m] = ha2[m + 1] * 19260817 + a[m];
	for (m = 1; m <= n; m++)
	{
		k = 0;
		for (i = m + 1; i <= n + 1; i += m)
		{
			jj = ha(ha1[i - 1] - ha1[i - m - 1] * power[m]);
			if (hash[jj] == ha1[i - 1] - ha1[i - m - 1] * power[m])
				continue;
			j2 = ha(ha2[i - m] - ha2[i] * power[m]);
			if (hash[j2] == ha2[i - m] - ha2[i] * power[m])
				continue;
			b[jj] = b[j2] = m, hash[jj] = ha1[i - 1] - ha1[i - m - 1] * power[m];
			hash[j2] = ha2[i - m] - ha2[i] * power[m], k++;
		}
		if (k > max)
			max = k, nans = 1, ans[1] = m;
		else if (k == max)
			nans++, ans[nans] = m;
	}
	printf("%lld %lld\n", max, nans);
	for (m = 1; m < nans; m++)
	{
		printf("%lld ", ans[m]);
	}
	printf("%lld", ans[m]);
	return 0;
}
