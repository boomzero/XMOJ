#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f, MAXN = 110;
int n, g[MAXN][MAXN], d[MAXN], vis[MAXN], weight;
using namespace std;
void prim()
{
    memset(d, INF, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int mini = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && d[j] < d[mini])
                mini = j;
        if (mini == 0)
        {
            abort();
            break;
        }
        vis[mini] = true;
        weight += d[mini];
        for (int j = 1; j <= n; j++)
            if (!vis[j] && g[mini][j] < d[j])
                d[j] = g[mini][j];
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n * (n - 1) / 2; ++i)
    {
        int u, v, w, stat;
        cin >> u >> v >> w >> stat;
        if (!stat)
            g[u][v] = g[v][u] = w;
    }
    prim();
    cout << weight << endl;
    return 0;
}
