#include <bits/stdc++.h>
typedef long long ll;
const ll N = 5005;
using namespace std;
ll n, m, Answer[N], k[N], x, y, Depth;
ll EdgeCount;
struct EDGE
{
    ll u, v;
} Edges[N * 2];
vector<ll> Vector[N];
bool Visited[N];
void AddEdge(ll u, ll v)
{
    Vector[u].push_back(v);
    Edges[EdgeCount].u = u;
    Edges[EdgeCount].v = v;
    EdgeCount++;
}
void DFS(ll u, ll Father)
{
    if (Visited[u])
        return;
    Visited[u] = 1;
    Depth++;
    k[Depth] = u;
    for (ll i = 0; i < Vector[u].size(); i++)
    {
        ll v = Vector[u][i];
        if (v == Father)
            continue;
        if ((v == y && u == x) || (v == x && u == y))
            continue;
        DFS(v, u);
    }
}
bool Check()
{
    for (ll i = 1; i <= n; i++)
    {
        if (k[i] > Answer[i])
            return false;
        else if (k[i] < Answer[i])
            return true;
    }
    return false;
}
void Solve(ll u, ll Father)
{
    if (Visited[u])
        return;
    Visited[u] = 1;
    Depth++;
    Answer[Depth] = u;
    for (ll i = 0; i < Vector[u].size(); i++)
    {
        ll v = Vector[u][i];
        if (v == Father)
            continue;
        Solve(v, u);
    }
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    for (ll i = 1; i <= n; i++)
        sort(Vector[i].begin(), Vector[i].end());
    if (n == m)
    {
        for (ll i = 1; i <= EdgeCount; i += 2)
        {
            Depth = 0;
            x = Edges[i].u;
            y = Edges[i].v;
            memset(Visited, 0, sizeof(Visited));
            DFS(1, -1);
            if (Depth < n)
                continue;
            if (Answer[1] == 0)
                memcpy(Answer, k, sizeof(k));
            else if (Check())
                memcpy(Answer, k, sizeof(k));
        }
        for (ll i = 1; i <= n; i++)
            printf("%lld ", Answer[i]);
    }
    else
    {
        Solve(1, -1);
        for (ll i = 1; i <= n; i++)
            printf("%lld ", Answer[i]);
    }
    return 0;
}
