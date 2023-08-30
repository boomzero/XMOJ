#include <bits/stdc++.h>
using namespace std;
long long n, v, c[110] /*体积*/, t[110] /*价值*/, m[110] /*个数*/, f[10010];
void zeroOnePack(long long f[], long long c, long long w)
{
	for (long long i = v; i >= c; i--)
		f[i] = max(f[i], f[i - c] + w);
}
void completePack(long long f[], long long c, long long w)
{
	for (long long i = c; i <= v; i++)
		f[i] = max(f[i], f[i - c] + w);
}
void multiPack(long long f[], long long c, long long w, long long m)
{
	if (c * m >= v)
	{
		completePack(f, c, w);
		return;
	}
	long long k = 1;
	while (k < m)
	{
		zeroOnePack(f, k * c, k * w);
		m -= k;
		k *= 2;
	}
	zeroOnePack(f, m * c, m * w);
}
int main()
{
	cin >> v >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> m[i] >> c[i] >> t[i];
	}
	for (long long i = 1; i <= n; i++)
	{
		multiPack(f, c[i], t[i], m[i]);
	}
	cout << f[v];
	return 0;
}
