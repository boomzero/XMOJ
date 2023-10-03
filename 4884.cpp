#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100'005;
struct PLANE
{
	ll ar, le;
};
ll n, m[2], Total[N][2];
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m[0], &m[1]);
	for (ll t = 0; t < 2; t++)
	{
		ll List[N] = {0};
		ll Layer = 0;
		ll Number[N] = {0};
		PLANE Planes[N];
		for (ll i = 1; i <= m[t]; ++i)
			scanf("%lld%lld", &Planes[i].ar, &Planes[i].le);
		sort(Planes + 1, Planes + m[t] + 1,
			 [](PLANE x, PLANE y)
			 {
				 return x.ar < y.ar;
			 });
		for (ll i = 1; i <= m[t]; ++i)
		{
			ll Temp = 0;
			for (ll j = 1; j <= Layer; ++j)
				if (Planes[i].ar > List[j])
				{
					Temp = j;
					break;
				}
			if (!Temp)
			{
				Layer++;
				List[Layer] = Planes[i].le;
				Number[Layer]++;
			}
			else
			{
				List[Temp] = Planes[i].le;
				Number[Temp]++;
			}
		}
		for (ll i = 1; i <= n; ++i)
			Total[i][t] = Number[i] + Total[i - 1][t];
	}
	ll Answer = -1;
	for (ll i = 0; i <= n; ++i)
		Answer = max(Answer, Total[i][0] + Total[n - i][1]);
	printf("%lld\n", Answer);
	return 0;
}
