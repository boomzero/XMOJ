#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500005;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
struct EDGE
{
    ll u, v, w, Next;
};
EDGE Edges[N];
ll n, m, EdgeCount, Head[N], Distance1[N], Distance2[N];
void AddEdge(ll u, ll v, ll w)
{
    Edges[EdgeCount] = {u, v, w, Head[u]};
    Head[u] = EdgeCount;
    EdgeCount++;
    Edges[EdgeCount] = {v, u, w, Head[v]};
    Head[v] = EdgeCount;
    EdgeCount++;
}
void BFS(ll x, ll Distance[])
{
    for (ll i = 0; i <= n; i++)
        Distance[i] = 0;
    Distance[x] = 0;
    queue<ll> Queue;
    Queue.push(x);
    while (!Queue.empty())
    {
        ll u = Queue.front();
        Queue.pop();
        for (ll i = Head[u]; i != -1; i = Edges[i].Next)
        {
            ll v = Edges[i].v;
            ll w = Edges[i].w;
            if (Distance[v] != 0 || v == x)
                continue;
            Distance[v] = Distance[u] + w;
            Queue.push(v);
        }
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    memset(Head, -1, sizeof(Head));
    for (ll i = 0; i < m; i++)
    {
        ll x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        AddEdge(x, y, z);
    }
    BFS(1, Distance1);
    ll DiameterFirst, DiameterLength, DiameterSecond;
    DiameterLength = -INF;
    for (ll i = 1; i <= n; i++)
        if (DiameterLength < Distance1[i])
        {
            DiameterLength = Distance1[i];
            DiameterFirst = i;
        }
    BFS(DiameterFirst, Distance1);
    DiameterLength = -INF;
    for (ll i = 1; i <= n; i++)
        if (DiameterLength < Distance1[i])
        {
            DiameterLength = Distance1[i];
            DiameterSecond = i;
        }
    BFS(DiameterSecond, Distance2);
    ll Answer = -INF;
    for (ll i = 1; i <= n; i++)
        Answer = max(Answer, min(Distance1[i], Distance2[i]));
    printf("%lld\n", Answer + DiameterLength);
    return 0;
}
