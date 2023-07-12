#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 10005;
const ll E = 200005;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
ll n, m, c[N], Father[N], Total, Answer = INF;
struct EDGE
{
    ll u, v, w;
} Edges[E];
ll Find(ll x)
{
    return x == Father[x] ? x : Father[x] = Find(Father[x]);
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
        Father[i] = i;
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &c[i]);
    Answer = *min_element(c + 1, c + n + 1);
    for (ll i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &Edges[i].u, &Edges[i].v, &Edges[i].w);
        Edges[i].w = Edges[i].w * 2 + c[Edges[i].u] + c[Edges[i].v];
    }
    sort(Edges + 1, Edges + m + 1,
         [](EDGE a, EDGE b)
         {
             return a.w < b.w;
         });
    for (ll i = 1; i <= m; i++)
    {
        ll u = Find(Edges[i].u);
        ll v = Find(Edges[i].v);
        if (u != v)
        {
            Father[u] = v;
            Answer += Edges[i].w;
            Total++;
        }
        if (Total == n - 1)
            break;
    }
    printf("%lld\n", Answer);
    return 0;
}
