#include <bits/stdc++.h>
using namespace std;
const int N = 300'005;
const int LOG_N = 20;
int n, a[N], Depth[N], Father[N][LOG_N], Count[N];
vector<int> Graph[N];
void DFS(int u, int f)
{
    Depth[u] = Depth[f] + 1;
    Father[u][0] = f;
    for (int i = 1; i < LOG_N; i++)
        Father[u][i] = Father[Father[u][i - 1]][i - 1];
    for (auto v : Graph[u])
        if (v != f)
            DFS(v, u);
}
int LCA(int u, int v)
{
    if (Depth[u] < Depth[v])
        swap(u, v);
    for (int i = LOG_N - 1; i >= 0; i--)
        if (Depth[Father[u][i]] >= Depth[v])
            u = Father[u][i];
    if (u == v)
        return u;
    for (int i = LOG_N - 1; i >= 0; i--)
        if (Father[u][i] != Father[v][i])
            u = Father[u][i], v = Father[v][i];
    return Father[u][0];
}
int main()
{
    freopen("visit.in", "r", stdin);
    freopen("visit.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    DFS(1, 0);
    Count[a[1]]++;
    for (int i = 1; i < n; i++)
    {
        int lca = LCA(a[i], a[i + 1]);
        int x = a[i];
        Count[x]++;
        while (x != lca)
        {
            x = Father[x][0];
            Count[x]++;
        }
        x = a[i + 1];
        while (x != lca)
        {
            Count[x]++;
            x = Father[x][0];
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", Count[i] - 1);
    return 0;
}
