#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005;
const ll LOG_N = 21;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
ll n, m, q, EdgeCount, Next[N * 2], Head[N * 2], To[N * 2], Depth[N], Fathers[N][LOG_N], Weight[N * 2], Distance[N];
void AddEdge(ll u, ll v, ll w)
{
    EdgeCount++;
    Next[EdgeCount] = Head[u];
    Head[u] = EdgeCount;
    To[EdgeCount] = v;
    Weight[EdgeCount] = w;
}
ll LCA(ll x, ll y)
{
    if (Depth[x] < Depth[y])
        swap(x, y);
    for (ll i = LOG_N - 1; i >= 0; i--)
    {
        if (Depth[Fathers[x][i]] >= Depth[y])
            x = Fathers[x][i];
        if (x == y)
            return x;
    }
    for (ll i = LOG_N - 1; i >= 0; i--)
        if (Fathers[x][i] != Fathers[y][i])
        {
            x = Fathers[x][i];
            y = Fathers[y][i];
        }
    return Fathers[x][0];
}
void DFS(ll x, ll Father)
{
    Fathers[x][0] = Father;
    Depth[x] = Depth[Father] + 1;
    for (ll i = Head[x]; i != 0; i = Next[i])
        if (To[i] != Father)
        {
            Distance[To[i]] = Distance[x] + Weight[i];
            DFS(To[i], x);
        }
}
int main()
{
    scanf("%lld%lld", &n, &q);
    for (ll i = 1; i < n; i++)
    {
        ll x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        AddEdge(x, y, z);
        AddEdge(y, x, z);
    }
    DFS(1, 0);
    for (ll i = 1; i <= LOG_N - 1; i++)
        for (ll j = 1; j <= n; j++)
            Fathers[j][i] = Fathers[Fathers[j][i - 1]][i - 1];
    for (ll i = 1; i <= q; i++)
    {
        ll p1, p2;
        scanf("%lld%lld", &p1, &p2);
        printf("%lld\n", Distance[p1] + Distance[p2] - Distance[LCA(p1, p2)] * 2);
    }
    return 0;
}
