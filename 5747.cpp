#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 1005;
const ld INF = 0x3FFF'FFFF'FFFF'FFFF;
bool Visited[N];
ll n, m, x[N], y[N];
ld Map[N][N], Distance[N];
void Prim()
{
    fill(Distance + 1, Distance + n + 1, INF);
    Distance[1] = 0;
    for (ll i = 1; i < n; i++)
    {
        ll u = 0;
        for (ll j = 1; j <= n; j++)
            if (!Visited[j] && (u == 0 || Distance[j] < Distance[u]))
                u = j;
        Visited[u] = true;
        for (ll j = 1; j <= n; j++)
            if (!Visited[j])
                Distance[j] = min(Distance[j], Map[u][j]);
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            Map[i][j] = INF;
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x[i], &y[i]);
        for (ll j = 1; j < i; j++)
            Map[i][j] = Map[j][i] = sqrt(
                (ld)(x[i] - x[j]) * (x[i] - x[j]) +
                (ld)(y[i] - y[j]) * (y[i] - y[j]));
    }
    for (ll i = 1, u, v; i <= m; i++)
    {
        scanf("%lld%lld", &u, &v);
        Map[u][v] = Map[v][u] = 0;
    }
    Prim();
    ld Answer = 0;
    for (ll i = 1; i <= n; i++)
        Answer += Distance[i];
    printf("%.2Lf\n", Answer);
    return 0;
}
