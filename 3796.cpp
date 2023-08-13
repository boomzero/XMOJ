#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 300005;
const ll LOG_N = 20;
const ll M = 600005;
ll n, a[N], EdgeCount, Head[N], LogDepth, Tag[N];
struct EDGE
{
    ll Next, v;
} Edges[M];
void AddEdge(ll u, ll v)
{
    EdgeCount++;
    Edges[EdgeCount].Next = Head[u];
    Edges[EdgeCount].v = v;
    Head[u] = EdgeCount;
}
ll Depth[N], Father[N][LOG_N], MaxDepth;
void PreDFS(ll u, ll f)
{
    for (ll i = Head[u]; i; i = Edges[i].Next)
    {
        ll v = Edges[i].v;
        if (v == f)
            continue;
        Father[v][0] = u;
        Depth[v] = Depth[u] + 1;
        PreDFS(v, u);
    }
    MaxDepth = max(MaxDepth, Depth[u]);
}
ll LCA(ll u, ll v)
{
    if (Depth[u] < Depth[v])
        swap(u, v);
    ll t = Depth[u] - Depth[v];
    ll x = 0;
    while (t)
    {
        if (t % 2 == 1)
            u = Father[u][x];
        t /= 2;
        x++;
    }
    if (u == v)
        return u;
    for (ll i = LogDepth; i >= 0; i--)
        if (Father[u][i] != Father[v][i])
        {
            u = Father[u][i];
            v = Father[v][i];
        }
    return Father[u][0];
}
void DFS(ll u)
{
    for (ll i = Head[u]; i; i = Edges[i].Next)
    {
        ll v = Edges[i].v;
        if (v == Father[u][0])
            continue;
        DFS(v);
        Tag[u] += Tag[v];
    }
}
int main()
{
    // freopen("visit.in", "r", stdin);
    // freopen("visit.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    PreDFS(1, 1);
    LogDepth = log2(MaxDepth);
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= LogDepth; j++)
            Father[i][j] = Father[Father[i][j - 1]][j - 1];
    for (ll i = 2; i <= n; i++)
    {
        ll LCAValue = LCA(a[i - 1], a[i]);
        Tag[a[i - 1]]++;
        Tag[Father[a[i]][0]]++;
        Tag[LCAValue]--;
        Tag[Father[LCAValue][0]]--;
    }
    DFS(1);
    for (ll i = 1; i <= n; i++)
        printf("%lld\n", Tag[i]);
    return 0;
}
