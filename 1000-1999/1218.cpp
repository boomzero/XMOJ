#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 25;
const ll M = 5005;
const ll INF = 0x7FFF'FFFF;
ll n, m;
ll Distance[N][N], f[N][M];
ll p[M], Number[M], Position[M], Sum[M], Condition[M];
ll LowBit(ll x)
{
	return x & (-x);
}
int main()
{
	scanf("%lld%lld", &n, &m);
	fill(f[0], f[0] + N * M, INF);
	fill(Distance[0], Distance[0] + N * N, INF);
	for (ll i = 1; i <= m; i++)
	{
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		x--, y--;
		Distance[x][y] = Distance[y][x] = min(z, Distance[x][y]);
	}
	for (ll i = 0; i < n; i++)
	{
		Position[1 << i] = i;
		f[0][1 << i] = 0;
	}
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < (1 << n); j++)
		{
			ll Total = 0;
			for (ll To = 0; To < n; To++)
			{
				if ((1 << To) & j)
					continue;
				p[Total] = 1 << To;
				Number[Total] = INF;
				for (ll k = j; k; k -= LowBit(k))
				{
					ll From = Position[LowBit(k)];
					Number[Total] = min(Number[Total], Distance[From][To] * (i + 1));
				}
				Total++;
			}
			for (ll k = 1; k < (1 << Total); k++)
			{
				Condition[k] = Condition[k - (LowBit(k))] | p[Position[LowBit(k)]];
				Sum[k] = Sum[k - (LowBit(k))] + Number[Position[LowBit(k)]];
				f[i + 1][j | Condition[k]] = min(f[i + 1][j | Condition[k]], f[i][j] + Sum[k]);
			}
		}
	ll Answer = INF;
	for (ll i = 0; i <= n; i++)
		Answer = min(Answer, f[i][(1 << n) - 1]);
	printf("%lld\n", Answer);
	return 0;
}
