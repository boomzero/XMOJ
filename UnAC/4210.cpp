#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
const ll INF = 0x7FFF'FFFF'FFFF'FFFF;
ll n, Head[N], EdgeCount, Distances[N], Answer = INF;
bool Visited[N];
struct EDGE
{
    ll v, w, Next;
} Edge[N * 2];
void AddEdge(ll u, ll v, ll w)
{
    EdgeCount++;
    Edge[EdgeCount].v = v;
    Edge[EdgeCount].w = w;
    Edge[EdgeCount].Next = Head[u];
    Head[u] = EdgeCount;
}
void Dijkstra(ll Start)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Queue;
    Distances[Start] = 0;
    Queue.push({0, Start});
    while (!Queue.empty())
    {
        ll u = Queue.top().second;
        ll w = Queue.top().first;
        Queue.pop();
        if (Visited[u])
            continue;
        Visited[u] = true;
        for (ll i = Head[u]; i; i = Edge[i].Next)
        {
            ll v = Edge[i].v;
            ll w = Edge[i].w;
            if (Distances[v] > Distances[u] + w)
            {
                Distances[v] = Distances[u] + w;
                Queue.push({Distances[v], v});
            }
        }
    }
}
vector<ll> Children[N];
ll NameLength[N];
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        ll m;
        char s[20] = {0};
        scanf("%s%lld", s, &m);
        NameLength[i] = strlen(s);
        if (m == 0)
            continue;
        for (ll j = 1; j <= m; j++)
        {
            ll v;
            scanf("%lld", &v);
            Children[i].push_back(v);
        }
    }
    for (ll i = 1; i <= n; i++)
        for (auto j : Children[i])
        {
            if (Children[j].size() != 0)
            {
                AddEdge(j, i, 3);
                AddEdge(i, j, NameLength[j] + 1);
            }
            else
                AddEdge(i, j, NameLength[j]);
        }
    for (ll i = 1; i <= n; i++)
        if (Children[i].size() != 0)
        {
            fill(Distances + 1, Distances + n + 1, INF);
            fill(Visited + 1, Visited + n + 1, false);
            Dijkstra(i);
            ll CurrentAnswer = 0;
            for (ll j = 1; j <= n; j++)
                if (Children[j].size() == 0)
                    CurrentAnswer += Distances[j];
            Answer = min(Answer, CurrentAnswer);
        }
    printf("%lld\n", Answer);
    return 0;
}
