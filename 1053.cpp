// 交叉点建图，直接指向的w=0，需要手工的w=1

#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

const int MAXN = 110;

const int INF = 100000000;

int n, s, e; // 点的个数，起点，终点

int w[MAXN][MAXN]; // w[i][j]表示是否连通 0默认 1需手动调节 INF不连通

bool vis[MAXN]; // 标记是否使用

int dist[MAXN]; // dist[i]表示从起点到点i的距离

void dijkstra()

{

    memset(vis, false, sizeof(vis)); // 清除所有的点

    for (int i = 1; i <= n; i++)
        dist[i] = w[s][i];

    dist[s] = 0;

    vis[s] = true; // 标记起点

    for (int i = 1; i < n; i++)
    { // 循环n-1次

        int x = 0, m = INF;

        for (int y = 1; y <= n; y++) // 在所有未标号的节点中，选出dist值的最小点x

            if (!vis[y] && dist[y] < m)

                m = dist[x = y];

        if (x == 0)
            break;

        vis[x] = true; // 给节点x标记

        for (int y = 1; y <= n; y++) // 更新 松弛操作

            if (!vis[y])

                dist[y] = min(dist[y], dist[x] + w[x][y]);
    }

    if (dist[e] == INF)
        printf("-1\n");

    else
        printf("%d\n", dist[e]);
}

int main()

{

    scanf("%d%d%d", &n, &s, &e);

    for (int i = 1; i <= n; i++)
    {

        dist[i] = INF;

        for (int j = 1; j <= n; j++)
            w[i][j] = (i == j ? 0 : INF);
    }

    int path, y;

    for (int i = 1; i <= n; i++)
    {

        scanf("%d", &path);

        for (int j = 1; j <= path; j++)
        {

            scanf("%d", &y);

            w[i][y] = (j == 1 ? 0 : 1); // 需手动调节
        }
    }

    dijkstra();

    return 0;
}
