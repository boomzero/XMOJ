#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500005;
const ll INF = 0x7FFF'FFFF;
struct EDGE
{
    ll u, v, w;
} Edges[N];
ll n, Father[N], Value[N], EdgeCount, Answer;
ll Find(ll x)
{
    return (Father[x] == x ? x : (Father[x] = Find(Father[x])));
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        Father[i] = i;
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &Value[i]);
    for (ll i = 1, x; i <= n; i++)
        for (ll j = 1; j <= n; j++)
        {
            scanf("%lld", &x);
            Edges[EdgeCount].u = i;
            Edges[EdgeCount].v = j;
            Edges[EdgeCount].w = x;
            EdgeCount++;
        }
    for (ll i = 1; i <= n; i++)
    {
        Edges[EdgeCount].u = i;
        Edges[EdgeCount].v = n + 1;
        Edges[EdgeCount].w = Value[i];
        EdgeCount++;
    }
    sort(Edges, Edges + EdgeCount,
         [](EDGE First, EDGE Second)
         {
             return First.w < Second.w;
         });
    for (ll i = 0; i < EdgeCount; i++)
    {
        ll FatherX = Find(Edges[i].u);
        ll FatherY = Find(Edges[i].v);
        if (FatherX != FatherY)
        {
            Father[FatherX] = FatherY;
            Answer += Edges[i].w;
        }
    }
    printf("%lld\n", Answer);
    return 0;
}
