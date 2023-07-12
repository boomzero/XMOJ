#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x7FFF'FFFF;
const ll N = 1005;
ll Head[N], Next[N], To[N], Weight[N], Distance[N], VisitCount[N];
bool Visited[N], HaveRing;
ll n, p, s, d, f, EdgeCount;
void AddEdge(ll u, ll v, ll w)
{
    EdgeCount++;
    To[EdgeCount] = v;
    Weight[EdgeCount] = w;
    Next[EdgeCount] = Head[u];
    Head[u] = EdgeCount;
}
void SPFA()
{
    fill(Distance + 1, Distance + n + 1, -INF);
    Distance[s] = d;
    queue<ll> q;
    q.push(s);
    Visited[s] = true;
    while (!q.empty())
    {
        ll v = q.front();
        q.pop();
        VisitCount[v]++;
        Visited[v] = false;
        for (ll p = Head[v]; p; p = Next[p])
        {
            ll u = To[p];
            ll w = Weight[p];
            if (Distance[u] < Distance[v] + w)
            {
                Distance[u] = Distance[v] + w;
                if (!Visited[u])
                {
                    Visited[u] = true;
                    if (VisitCount[u] == n)
                    {
                        HaveRing = 1;
                        return;
                    }
                    q.push(u);
                }
            }
        }
    }
}
int main()
{
    scanf("%lld%lld%lld%lld%lld", &d, &p, &n, &f, &s);
    for (ll i = 1; i <= p; i++)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        AddEdge(x, y, d);
    }
    for (ll i = 1; i <= f; i++)
    {
        ll x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        AddEdge(x, y, d - z);
    }
    SPFA();
    if (HaveRing)
        printf("-1\n");
    else
        printf("%lld\n", *max_element(Distance + 1, Distance + n + 1));
    return 0;
}
