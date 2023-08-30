#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int INF = 0x7f7f7f7f;
int n, m, mapp[MAXN][MAXN], dist[MAXN], vis[MAXN], weight;
void prim()
{
    int mini = 1, w;
    memset(dist, INF, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    vis[1] = true;
    dist[1] = weight = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            if (!vis[j] && mapp[mini][j] < dist[j])
                dist[j] = mapp[mini][j];
        mini = 0, w = INF;
        for (int j = 1; j <= n; ++j)
            if (!vis[j] && dist[j] < w)
                w = dist[mini = j];
        vis[mini] = true;
        weight += w;
    }
}
int main()
{
    scanf("%d", &n);
    memset(mapp, INF, sizeof(mapp));
    m = n * (n - 1) / 2;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        mapp[x][y] = mapp[y][x] = z;
    }
    prim();
    cout << weight << endl;
    return 0;
}
