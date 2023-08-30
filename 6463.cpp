#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define hash hash1
typedef long long ll;
int n, c[410][4];
ll ans = 0, h[410];
map<ll, int> mp;
ll hash(ll a, ll b, ll c, ll d)
{
	return a << 30 | b << 20 | c << 10 | d;
}
void add(ll x, int k)
{
	for (int i = 4; i; x = x >> 10 | (x & 1023) << 30, i--)
		mp[x] += k;
	return;
}
template <typename T>
void read(T &a)
{
	a = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	do
	{
		a = a * 10 + ch - '0';
		ch = getchar();
	} while ('0' <= ch && ch <= '9');
	a *= f;
}
int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	mp.clear();
	read(n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", c[i] + 0, c[i] + 1, c[i] + 2, c[i] + 3);
		h[i] = hash(c[i][0], c[i][1], c[i][2], c[i][3]);
		add(h[i], 1);
	}
	for (int i = 1; i < n - 4; i++)
	{
		add(h[i], -1);
		for (int j = i + 1; j <= n; j++)
		{
			add(h[j], -1);
			for (int k = 0; k < 4; k++)
			{
				ll a[4];
				a[0] = hash(c[i][3], c[i][2], c[j][(k + 1) % 4], c[j][k]);
				a[1] = hash(c[i][2], c[i][1], c[j][(k + 2) % 4], c[j][(k + 1) % 4]);
				a[2] = hash(c[i][1], c[i][0], c[j][(k + 3) % 4], c[j][(k + 2) % 4]);
				a[3] = hash(c[i][0], c[i][3], c[j][k], c[j][(k + 3) % 4]);
				if (mp[a[0]] == 0 || mp[a[1]] == 0 || mp[a[2]] == 0 || mp[a[3]] == 0)
					continue;
				ll res = 1;
				for (int l = 0; l < 4; l++)
				{
					res *= mp[a[l]];
					add(a[l], -1);
				}
				ans += res;
				for (int l = 0; l < 4; l++)
					add(a[l], 1);
			}
			add(h[j], 1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
