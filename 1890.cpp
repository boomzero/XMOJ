#include <bits/stdc++.h>

#define INF 0x7fffffff

using namespace std;

const int Maxt = 32;

const int Maxn = 3610;

const int Maxm = Maxn * 5;

int n, m, p;

bool a[Maxt][Maxt], vis[Maxn];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int predis[Maxt][Maxt], dis[Maxn];

struct game
{

    int next, to, w;

} e[Maxm];

int top, head[Maxn];

void add(int u, int v, int val)
{

    top++;

    e[top].to = v;

    e[top].w = val;

    e[top].next = head[u];

    head[u] = top;
}

struct start
{

    int x, y;

} nxt, cur;

queue<start> q;

queue<int> que;

int numbers(int i, int j)
{

    j--;

    return (i - 1) * m + j << 2;
}

void bfs(int ex, int ey, int px, int py, int d)
{

    int cx, cy, nx, ny;

    memset(predis, -1, sizeof(predis));

    predis[px][py] = 1;

    predis[ex][ey] = 0;

    cur.x = ex, cur.y = ey;

    q.push(cur);

    while (!q.empty())
    {

        cur = q.front();

        q.pop();

        cx = cur.x, cy = cur.y;

        for (int i = 0; i < 4; ++i)
        {

            nx = cur.x + dx[i], ny = cur.y + dy[i];

            if (a[nx][ny] && predis[nx][ny] == -1)
            {

                predis[nx][ny] = predis[cx][cy] + 1;

                nxt.x = nx, nxt.y = ny;

                q.push(nxt);
            }
        }
    }

    if (d == 8)
        return;

    int tmp = numbers(px, py);

    for (int i = 0; i < 4; ++i)
    {

        int x = px + dx[i], y = py + dy[i];

        if (predis[x][y] > 0)

            add(tmp + d, tmp + i, predis[x][y]);
    }

    add(tmp + d, numbers(ex, ey) + (d + 2) % 4, 1);
}

void spfa(int sx, int sy)
{

    int tmp;

    memset(dis, -1, sizeof(dis));

    for (int i = 0; i < 4; ++i)
    {

        int x = sx + dx[i], y = sy + dy[i];

        if (predis[x][y] != -1)
        {

            tmp = numbers(sx, sy) + i;

            dis[tmp] = predis[x][y];

            que.push(tmp);
        }
    }

    int u;

    while (!que.empty())
    {

        u = que.front();

        que.pop();

        vis[u] = false;

        for (int i = head[u]; i; i = e[i].next)
        {

            int v = e[i].to;

            if (dis[v] == -1 || dis[v] > dis[u] + e[i].w)
            {

                dis[v] = dis[u] + e[i].w;

                if (!vis[v])
                {

                    vis[v] = true;

                    que.push(v);
                }
            }
        }
    }
}

int main()
{

    scanf("%d%d%d", &n, &m, &p);

    for (int i = 1; i <= n; ++i)

        for (int j = 1; j <= m; ++j)

            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; ++i)

        for (int j = 1; j <= m; ++j)

            if (a[i][j])
            {

                if (a[i - 1][j])
                    bfs(i - 1, j, i, j, 0);

                if (a[i][j + 1])
                    bfs(i, j + 1, i, j, 1);

                if (a[i + 1][j])
                    bfs(i + 1, j, i, j, 2);

                if (a[i][j - 1])
                    bfs(i, j - 1, i, j, 3);
            }

    int ex, ey, sx, sy, tx, ty, ans;

    while (p--)
    {

        scanf("%d%d%d%d%d%d", &ex, &ey, &sx, &sy, &tx, &ty);

        if (sx == tx && sy == ty)
        {

            printf("0\n");

            continue;
        }

        bfs(ex, ey, sx, sy, 8);

        spfa(sx, sy);

        ans = INF;

        int tmp = numbers(tx, ty);

        for (int i = 0; i < 4; ++i)

            if (dis[tmp + i] != -1)

                ans = min(ans, dis[tmp + i]);

        if (ans == INF)

            ans = -1;

        printf("%d\n", ans);
    }

    return 0;
}
