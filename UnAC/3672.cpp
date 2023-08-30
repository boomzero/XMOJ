#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3005;
ll n, m, Head[N], EdgeCount;
set<ll> Points;
struct EDGE
{
    ll Next, To;
} Edges[N];
void AddEdge(ll u, ll v)
{
    Edges[++EdgeCount].Next = Head[u];
    Edges[EdgeCount].To = v;
    Head[u] = EdgeCount;
}
bool Connected()
{
    bool Visited[N];
    memset(Visited, 0, sizeof(Visited));
    queue<ll> Q;
    Q.push(*Points.begin());
    Visited[*Points.begin()] = true;
    while (!Q.empty())
    {
        ll u = Q.front();
        Q.pop();
        for (ll i = Head[u]; i != -1; i = Edges[i].Next)
        {
            ll v = Edges[i].To;
            if (!Visited[v])
            {
                Visited[v] = true;
                Q.push(v);
            }
        }
    }
    for (ll i = 1; i <= n; i++)
        if (Points.count(i) && !Visited[i])
            return false;
    return true;
}
void RemovePoint(ll x)
{
    for (ll i = 1; i <= n; i++)
        if (i != x)
            for (ll j = Head[i]; j != -1; j = Edges[j].Next)
                if (Edges[j].To == x)
                {
                    Edges[j].To = 0;
                    break;
                }
    for (ll i = Head[x]; i != -1; i = Edges[i].Next)
        Edges[i].To = 0;
    Head[x] = -1;
    Points.erase(x);
}
int main()
{
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    memset(Head, -1, sizeof(Head));
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
        Points.insert(i);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        AddEdge(u, v);
    }
    printf("%s\n", Connected() ? "YES" : "NO");
    for (ll i = 1; i < n; i++)
    {
        ll x;
        scanf("%d", &x);
        RemovePoint(x);
        printf("%s\n", Connected() ? "YES" : "NO");
    }
    return 0;
}
