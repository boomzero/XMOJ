#include <bits/stdc++.h>
using namespace std;
#define MAXN 5000
#define mod 1000000007
inline int read()
{
	register int x = 0, ch;
	while (!isdigit(ch = getchar()))
		;
	while (isdigit(ch))
		x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
int f[MAXN + 1][MAXN + 1], s[MAXN + 1], l[MAXN + 1], y[MAXN + 1], cnt[26];
inline int quick_pow(register int x, register int k)
{
	register int s = 1;
	while (k)
	{
		if (k & 1)
			s = (1LL * s * x) % mod;
		x = (1LL * x * x) % mod;
		k >>= 1;
	}
	return s;
}
int main()
{
	freopen("rhyme.in", "r", stdin);
	freopen("rhyme.out", "w", stdout);
	register int n = read(), m = read(), k = read();
	s[0] = 1;
	for (register int i = 1; i <= n; i++)
		l[i] = read(), y[i] = read();
	for (register int i = 1; i <= k; i++)
	{
		for (register int j = 1; j <= n; j++)
		{
			if (i >= l[j])
			{
				f[i][y[j]] = (f[i][y[j]] + s[i - l[j]]) % mod;
				s[i] = (s[i] + s[i - l[j]]) % mod;
			}
		}
	}
	for (register int i = 1; i <= m; i++)
	{
		register char ch;
		while (!isalpha(ch = getchar()))
			;
		cnt[ch - 'A']++;
	}
	register int res = 1;
	for (register int i = 0; i < 26; i++)
	{
		if (!cnt[i])
			continue;
		register int ans = 0;
		for (register int j = 1; j <= n; j++)
			if (f[k][j])
				ans = (ans + quick_pow(f[k][j], cnt[i])) % mod;
		res = 1LL * res * ans % mod;
	}
	printf("%d", res);
	return 0;
}
