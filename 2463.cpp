#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, g[N][N], vis[N], ans[N], tot;
void print()
{
    for (int i = 1; i < n; ++i)
        printf("%d-", ans[i]);
    printf("%d\n", ans[n]);
}
void dfs(int u)
{
    ans[++tot] = u;
    vis[u] = 1;
    if (tot == n)
    {
        print();
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (g[u][i] && !vis[i])
            dfs(i);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &g[i][j]);
    dfs(1);
    return 0;
}
