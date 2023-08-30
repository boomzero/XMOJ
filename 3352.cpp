#include <bits/stdc++.h>

using namespace std;

const int N = 410;

struct Node
{

    int pos, tim;

    bool operator<(const Node &n) const
    {

        return tim < n.tim;
    }

} p[N];

int n, d[N][N], dist[N];

vector<int> edges[N];

bool vis[N];

void spfa()

{

    queue<int> q;

    q.push(0);

    while (!q.empty())
    {

        int u = q.front();
        q.pop();

        vis[u] = 0;

        for (int i = 0, v; i < edges[u].size(); ++i)
        {

            v = edges[u][i];

            if (dist[u] + 1 > dist[v])
            {

                dist[v] = dist[u] + 1;

                if (!vis[v])
                {

                    vis[v] = 1;

                    q.push(v);
                }
            }
        }
    }
}

int main()

{

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {

        scanf("%d", &p[i].tim);

        p[i].pos = i;
    }

    sort(p + 1, p + n + 1);

    for (int i = 1; i <= n; ++i)

        for (int j = 1; j <= n; ++j)

            scanf("%d", &d[i][j]);

    for (int i = 1; i <= n; ++i)

        d[0][i] = d[1][i];

    for (int i = 0; i <= n; ++i)

        for (int j = i + 1; j <= n; ++j)

            if (p[i].tim + d[p[i].pos][p[j].pos] <= p[j].tim)

                edges[i].push_back(j);

    spfa();

    int ans = 0;

    for (int i = 1; i <= n; ++i)

        ans = max(ans, dist[i]);

    printf("%d\n", ans);

    return 0;
}
