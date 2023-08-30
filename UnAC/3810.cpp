#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005;
const ll M = 105;
const ll INF = 0x3FFF'FFFF;
ll k, m, s, t, Head[N], EdgeCount, Distance[N];
struct EDGE
{
    ll u, w, Next;
} Edges[M];
void AddEdge(ll u, ll v, ll w)
{
    EdgeCount++;
    Edges[EdgeCount].u = v;
    Edges[EdgeCount].w = w;
    Edges[EdgeCount].Next = Head[u];
    Head[u] = EdgeCount;
}
void Dijkstra()
{
    Distance[s] = 0;
    priority_queue<pair<ll, pair<ll, ll>>> q;
    q.push({0, {1, s}});
    while (!q.empty())
    {
        ll VisitedEdges = q.top().second.first;
        if (VisitedEdges > k)
            break;
        ll u = q.top().second.second;
        q.pop();
        for (ll i = Head[u]; i; i = Edges[i].Next)
        {
            ll v = Edges[i].u;
            if (Distance[v] > Distance[u] + Edges[i].w)
            {
                Distance[v] = Distance[u] + Edges[i].w;
                q.push({-Distance[v], {VisitedEdges + 1, v}});
            }
        }
    }
}
int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    scanf("%lld%lld%lld%lld", &k, &m, &s, &t);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, w;
        scanf("%lld%lld%lld", &w, &u, &v);
        AddEdge(u, v, w);
        AddEdge(v, u, w);
    }
    fill(Distance, Distance + N, INF);
    Dijkstra();
    printf("%lld\n", Distance[t]);
    return 0;
}
