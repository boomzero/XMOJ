#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100'005;
const ll M = 2000'005;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
struct EDGE
{
    ll To, Next;
    ll Weight;
} Edges[M];
ll Head[N], EdgeCount;
void AddEdge(ll u, ll v, ll w)
{
    EdgeCount++;
    Edges[EdgeCount].To = v;
    Edges[EdgeCount].Next = Head[u];
    Edges[EdgeCount].Weight = w;
    Head[u] = EdgeCount;
}
ll n, m, s, t, Distance[N];
bool Visited[N];
void Dijkstra()
{
    for (ll i = 1; i <= n; i++)
        Distance[i] = INF;
    Distance[s] = 0;
    priority_queue<pair<ll, ll>> PriorityQueue;
    PriorityQueue.push(make_pair(0, s));
    while (!PriorityQueue.empty())
    {
        ll u = PriorityQueue.top().second;
        PriorityQueue.pop();
        if (Visited[u])
            continue;
        Visited[u] = true;
        for (ll i = Head[u]; i; i = Edges[i].Next)
        {
            ll v = Edges[i].To;
            ll w = Edges[i].Weight;
            if (Distance[v] > Distance[u] + w)
            {
                Distance[v] = Distance[u] + w;
                PriorityQueue.push(make_pair(-Distance[v], v));
            }
        }
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        AddEdge(u, v, w);
        AddEdge(v, u, w);
    }
    scanf("%lld%lld", &s, &t);
    Dijkstra();
    if (Distance[t] == INF)
        printf("-1\n");
    else
        printf("%lld\n", Distance[t]);
    return 0;
}
