#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 10005;
ll n, m, s, e, Distance[N];
vector<ll> Edge[N];
bool CanVisit[N], NotVisited[N];
void Pre()
{
    queue<ll> Queue;
    CanVisit[e] = true;
    Queue.push(e);
    while (!Queue.empty())
    {
        ll u = Queue.front();
        Queue.pop();
        for (ll i = 0, j = Edge[u].size(); i < j; i++)
        {
            ll v = Edge[u][i];
            if (!CanVisit[v])
            {
                CanVisit[v] = true;
                Queue.push(Edge[u][i]);
            }
        }
    }
    memcpy(NotVisited, CanVisit, sizeof(CanVisit));
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= m; i++)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        if (a == b)
            continue;
        Edge[b].push_back(a);
    }
    scanf("%lld%lld", &s, &e);
    Pre();
    for (ll i = 1; i <= n; i++)
        if (!CanVisit[i])
            for (ll j = 0, k = Edge[i].size(); j < k; j++)
                if (NotVisited[Edge[i][j]])
                    NotVisited[Edge[i][j]] = false;
    queue<ll> Queue;
    Queue.push(e);
    while (!Queue.empty())
    {
        ll u = Queue.front();
        Queue.pop();
        for (ll i = 0, j = Edge[u].size(); i < j; i++)
        {
            ll v = Edge[u][i];
            if (NotVisited[v])
            {
                Queue.push(v);
                NotVisited[v] = false;
                Distance[v] = Distance[u] + 1;
            }
        }
    }
    printf("%lld\n", (Distance[s] == 0 ? -1 : Distance[s]));
    return 0;
}
