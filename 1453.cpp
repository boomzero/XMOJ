#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005;
ll t, n, m, Father[N];
vector<ll> Table[N];
ll Find(ll x)
{
    return Father[x] == x ? x : Father[x] = Find(Father[x]);
}
void Union(ll x, ll y)
{
    ll fx = Find(x), fy = Find(y);
    if (fx != fy)
        Father[fx] = fy;
}
int main()
{
    scanf("%lld", &t);
    while (t-- > 0)
    {
        scanf("%lld%lld", &n, &m);
        for (ll i = 1; i <= n; i++)
            Father[i] = i;
        for (ll i = 1; i <= n; i++)
            Table[i].clear();
        for (ll i = 1; i <= m; i++)
        {
            ll u, v;
            scanf("%lld%lld", &u, &v);
            Union(u, v);
        }
        for (ll i = 1; i <= n; i++)
            Table[Find(i)].push_back(i);
        ll Answer = 0;
        for (ll i = 1; i <= n; i++)
            Answer += ceil(Table[i].size() / 10.0);
        printf("%lld\n", Answer);
    }
    return 0;
}
