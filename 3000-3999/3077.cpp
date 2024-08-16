#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a, i##_end_ = b; i <= i##_end_; ++i)
#define DREP(i, a, b) for (int i = a, i##_end_ = b; i >= i##_end_; --i)
typedef long long ll;
using namespace std;
template <typename T>
void read(T &_)
{
	_ = 0;
	T f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (; isdigit(c); c = getchar())
		_ = (_ << 1) + (_ << 3) + (c ^ '0');
	_ *= f;
}
const int maxn = 2000 + 10;
const int mod = 1e9 + 7;
int n, f[maxn][maxn * 3][2];
char s[4][maxn];
int fac[maxn * 3], ifac[maxn * 3];
void inc(int &x, int y)
{
	(x += y) >= mod ? x -= mod : x < 0 ? x += mod
									   : 0;
}
int quickpow(int x, int y)
{
	int ret = 1;
	x %= mod;
	while (y)
	{
		if (y & 1)
			ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return ret;
}
void math_init()
{
	fac[0] = 1;
	REP(i, 1, 6000)
	fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[6000] = quickpow(fac[6000], mod - 2);
	DREP(i, 5999, 0)
	ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
int calc(int x, int y)
{
	if (x < 0 || y < 0 || x < y)
		return 0;
	return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n);
	REP(i, 1, 3)
	scanf("%s", s[i] + 1);
	REP(i, 1, n)
	{
		if (s[1][i] == 'x' && (i == 1 || i == n || s[1][i - 1] == 'x' || s[1][i + 1] == 'x'))
			puts("0"), exit(0);
		if (s[3][i] == 'x' && (i == 1 || i == n || s[3][i - 1] == 'x' || s[3][i + 1] == 'x'))
			puts("0"), exit(0);
	}
	math_init();
	int sum = 0, now = 0, ans = 1;
	if (s[2][1] == 'x')
	{
		f[1][1][0] = 1, now = 1;
		if (n == 1 || s[2][2] == 'o')
			sum = 1, now = 0;
	}
	REP(i, 2, n)
	{
		int cur = (s[1][i] == 'x') + (s[3][i] == 'x');
		if (s[2][i] == 'o')
		{
			sum += cur;
			ans = 1ll * ans * fac[cur] % mod * calc(sum, cur) % mod;
			continue;
		}
		++cur;
		now += cur;
		REP(j, 1, now)
		{
			int per = fac[cur - 1];
			if (now == cur)
			{
				if (j == cur)
					f[i][j][0] = per;
				if (i < n && j != cur)
					f[i][j][1] = per;
			}
			else
			{
				inc(f[i][j][0], 1ll * f[i - 1][now - cur][0] * per % mod * calc(j - 1, cur - 1) % mod);
				inc(f[i][j][0], 1ll * (f[i - 1][now - cur][1] - f[i - 1][max(j - cur, 0)][1]) * per % mod * calc(j - 1, cur - 1) % mod);
				if (i < n)
				{
					if (cur == 2)
						inc(f[i][j][1], 1ll * f[i - 1][min(now - cur, j - 1)][0] * per % mod * (now - j) % mod);
					if (cur == 3)
					{
						inc(f[i][j][1], 1ll * f[i - 1][min(now - cur, j - 1)][0] * per % mod * calc(now - j, 2) % mod);
						inc(f[i][j][1], 1ll * f[i - 1][max(j - 2, 0)][0] * per % mod * (j - 1) % mod * (now - j) % mod);
					}
				}
			}
		}
		if (i == n || s[2][i + 1] == 'o')
		{
			sum += now;
			int ts = 0;
			REP(j, 1, now)
			inc(ts, (f[i][j][0] + f[i][j][1] * (i < n)) % mod);
			ans = 1ll * ans * ts % mod * calc(sum, now) % mod;
			now = 0;
		}
		REP(j, 1, now)
		{
			inc(f[i][j][0], f[i][j - 1][0]);
			inc(f[i][j][1], f[i][j - 1][1]);
		}
	}
	printf("%d", ans);
	return 0;
}
