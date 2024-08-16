#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2505;
vector<ll> G[N];
ll n, m, k, w[N], Distance[N];
bool ok[N][N];
vector<ll> f[N];
void BFS(ll x)
{
    memset(Distance, -1, sizeof(Distance));
    queue<ll> Queue;
    Queue.push(x);
    Distance[x] = 0;
    while (!Queue.empty())
    {
        ll u = Queue.front();
        Queue.pop();
        if (u != x)
        {
            ok[x][u] = true;
            if (x != 1 && ok[1][u])
            {
                f[x].push_back(u);
                sort(f[x].begin(), f[x].end(),
                     [](ll u, ll v)
                     {
                         return w[u] > w[v];
                     });
                if (f[x].size() > 3)
                    f[x].pop_back();
            }
        }
        if (Distance[u] == k + 1)
            continue;
        for (ll v : G[u])
            if (Distance[v] == -1)
            {
                Distance[v] = Distance[u] + 1;
                Queue.push(v);
            }
    }
}
int main()
{
    freopen("holiday.in", "r", stdin);
    freopen("holiday.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    scanf("%lld", &k);
    for (ll i = 2; i <= n; i++)
        scanf("%lld", &w[i]);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
        BFS(i);
    ll Answer = 0;
    for (ll b = 2; b <= n; b++)
        for (ll c = 2; c <= n; c++)
            if (ok[b][c])
                for (ll a : f[b])
                    for (ll d : f[c])
                        if (a != c && b != d && a != d)
                            Answer = max(Answer, w[a] + w[b] + w[c] + w[d]);
    printf("%lld\n", Answer);
    return 0;
}
