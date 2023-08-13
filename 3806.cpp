#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 305;
const ll M = 25005;
const ll T = 40005;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
ll m, n, t, Head[N], EdgeCount, Distances[N];
struct EDGE
{
    ll u, v, w, Next;
} Edges[M];
struct QUERY
{
    ll Index, a, b, Answer;
} Querys[T];
void AddEdge(ll u, ll v, ll w)
{
    EdgeCount++;
    Edges[EdgeCount].u = u;
    Edges[EdgeCount].v = v;
    Edges[EdgeCount].w = w;
    Edges[EdgeCount].Next = Head[u];
    Head[u] = EdgeCount;
}
void Dijkstra(ll Start)
{
    fill(Distances + 1, Distances + n + 1, INF);
    Distances[Start] = 0;
    priority_queue<pair<ll, ll>,
                   vector<pair<ll, ll>>,
                   greater<pair<ll, ll>>>
        PriorityQueue;
    PriorityQueue.push({0, Start});
    while (!PriorityQueue.empty())
    {
        ll u = PriorityQueue.top().second;
        PriorityQueue.pop();
        for (ll i = Head[u]; i; i = Edges[i].Next)
        {
            ll v = Edges[i].v;
            ll w = Edges[i].w;
            if (Distances[v] > max(Distances[u], w))
            {
                Distances[v] = max(Distances[u], w);
                PriorityQueue.push({Distances[v], v});
            }
        }
    }
}
int main()
{
    freopen("route.in", "r", stdin);
    freopen("route.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &t);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        AddEdge(u, v, w);
    }
    for (ll i = 1; i <= t; i++)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        Querys[i].Index = i;
        Querys[i].a = a;
        Querys[i].b = b;
    }
    sort(Querys + 1, Querys + t + 1,
         [](QUERY a, QUERY b)
         {
             if (a.a == b.a)
                 return a.b < b.b;
             return a.a < b.a;
         });
    for (ll i = 1; i <= t; i++)
    {
        if (i == 1 || Querys[i].a != Querys[i - 1].a)
            Dijkstra(Querys[i].a);
        Querys[i].Answer = (Distances[Querys[i].b] == INF ? -1 : Distances[Querys[i].b]);
    }
    sort(Querys + 1, Querys + t + 1,
         [](QUERY a, QUERY b)
         {
             return a.Index < b.Index;
         });
    for (ll i = 1; i <= t; i++)
        printf("%lld\n", Querys[i].Answer);
    return 0;
}
