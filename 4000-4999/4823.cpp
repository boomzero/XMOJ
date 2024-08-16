#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int T, n, vis[maxn], s[3];
vector<int> g[maxn];
queue<int> q;
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (int i = 1, u, v; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            g[u].push_back(v), g[v].push_back(u);
        }
        s[1] = s[2] = 0;
        memset(vis, 0, sizeof(vis));
        vis[1] = 1;
        q.push(1);
        vis[n] = 2;
        q.push(n);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : g[u])
                if (vis[v] == 0)
                    ++s[vis[v] = vis[u]], q.push(v);
        }
        puts(s[1] > s[2] ? "XM" : "XH");
    }
    return 0;
}
